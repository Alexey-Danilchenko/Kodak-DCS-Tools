// 
// PPC Helper
// 
// helps by automatically setting up common stack variables and such
// in a function. This makes it easier to see the stack variables
// used inside a function as well as the arguements passed to that function
// 

#include <ida.hpp>
#include <idp.hpp>
#include <auto.hpp>
#include <name.hpp>
#include <bytes.hpp>
#include <loader.hpp>
#include <kernwin.hpp>
#include <frame.hpp>

#include <allins.hpp>

#define PPC_HELPER_VERSION	"v1.0"


int PPCHelper_ConvertFunction(func_t* pFunc)
{
	ea_t start = pFunc->startEA;
	ea_t end = pFunc->endEA;
//	struc_t* p_frame = get_frame(pFunc);
	
	const int MAX_REGS = 32;
	bool is_reg_saved[MAX_REGS];	// r0 - r31
	for(int i=0; i<MAX_REGS; i++)
		is_reg_saved[i] = false;
	bool is_arg_saved[MAX_REGS];	// r0 - r31
	for(int i=0; i<MAX_REGS; i++)
		is_arg_saved[i] = false;
	
	// process function from start to end
	for(ea_t ea=start; ea<end; ea+=4)
	{
		// get mnemonic
		char mnem[256];
		if( !ua_mnem(ea, mnem, sizeof(mnem)) )
			return false;
		tag_remove(mnem, mnem, sizeof(mnem));
		char* ptr = (char*)qstrstr(mnem, ".");
		if(ptr) *ptr = 0;
		// prepare cmd struct for this address
		decode_insn(ea);
		// fix mnemonic for "bl"
		if( cmd.itype == 13 && (cmd.auxpref & 8) )
		{
			qstrncpy(mnem, "bl", sizeof(mnem));
		}
		// fix mnemonic for "blr"
		else if( cmd.itype == 320 && cmd.auxpref == 0x500 )
		{
			qstrncpy(mnem, "blr", sizeof(mnem));
		}
		

		// handle register saving
		if( (!qstrcmp(mnem, "stdu") || !qstrcmp(mnem, "std")) &&
			cmd.Op1.type == o_reg &&
			cmd.Op2.type == o_displ &&
			!is_reg_saved[cmd.Op1.reg] &&
			cmd.Op2.reg == 1 ) // 1 == "sp"
		{
			int src_reg = cmd.Op1.reg;
			ea_t offset  = cmd.Op2.addr;
			int dst_reg = cmd.Op2.reg;
			char name[256];
			if( src_reg == 0 )
				qsnprintf(name, sizeof(name), "save_lr");
			else if( src_reg == 1 )
				qsnprintf(name, sizeof(name), "save_sp");
			else
				qsnprintf(name, sizeof(name), "save_r%d", src_reg);
			add_stkvar2(pFunc, name, offset, 0, NULL, 0);
			is_reg_saved[cmd.Op1.reg] = true;
			//msg("%08X : stdu %%r%d, %d(%%r%d)\n", (unsigned int)ea, src_reg, offset, dst_reg);
		}

		// handle arg saving
		else if( !qstrcmp(mnem, "mr") &&
			cmd.Op1.type == o_reg &&
			cmd.Op2.type == o_reg &&
			!is_arg_saved[cmd.Op2.reg] &&
			cmd.Op2.reg >= 3 )	// args begin at r3
		{
			int dst_reg = cmd.Op1.reg;
			int src_reg = cmd.Op2.reg;
			char canon[256];
			qsnprintf(canon, sizeof(canon), "%%r%d", dst_reg);
			char name[256];
			qsnprintf(name, sizeof(name), "arg%d", src_reg-3);
			add_regvar(pFunc, start, end, canon, name, NULL);
			is_arg_saved[cmd.Op2.reg] = true;
			//msg("%08X : mr   %%r%d, %%r%d\n", (unsigned int)ea, dst_reg, src_reg);
		}

		// if a function is called, then no more args can be saved
		else if( !qstrcmp(mnem, "bl") )
		{
			break;
		}
	}
	
	// process function from start to end
	msg("processing end to start (%08X to %08X)  -  %d\n", (unsigned int)end, (unsigned int)start, PPC_balways);
	bool is_in_return_point = false;
	for(ea_t ea=end-4; ea>start; ea-=4)
	{
		// get mnemonic
		char mnem[256];
		if( !ua_mnem(ea, mnem, sizeof(mnem)) )
			return false;
		tag_remove(mnem, mnem, sizeof(mnem));
		char* ptr = (char*)qstrstr(mnem, ".");
		if(ptr) *ptr = 0;
		// prepare cmd struct for this address
		decode_insn(ea);
		// fix mnemonic for "bl"
		if( cmd.itype == 13 && (cmd.auxpref & 8) )
		{
			qstrncpy(mnem, "bl", sizeof(mnem));
		}
		// fix mnemonic for "blr"
		else if( cmd.itype == 320 && cmd.auxpref == 0x500 )
		{
			qstrncpy(mnem, "blr", sizeof(mnem));
		}
//			msg("%08X: %3s  inst_type = %d,  insgpref = %d,  segpref = %d,  auxpref = %d\n", (unsigned int)ea, mnem, cmd.itype, cmd.segpref, cmd.insnpref, cmd.auxpref);

			//qstrncpy(mnem, "bl", sizeof(mnem));
/*			msg("%08X: %s  %d %d %d (%d %d %d %d) (%d %d %d %d) (%d %d %d %d)  : %X %X %X  : %X %X %X  : %X %X %X  : %X %X %X  : %X %X %X  : %X %X %X\n",
			(unsigned int)ea, mnem, cmd.Op1.type, cmd.Op2.type, cmd.Op3.type,
			cmd.Op1.specflag1, cmd.Op1.specflag2, cmd.Op1.specflag3, cmd.Op1.specflag4,
			cmd.Op2.specflag1, cmd.Op2.specflag2, cmd.Op2.specflag3, cmd.Op2.specflag4,
			cmd.Op3.specflag1, cmd.Op3.specflag2, cmd.Op3.specflag3, cmd.Op3.specflag4,
			(unsigned int)cmd.Op1.specval, (unsigned int)cmd.Op2.specval, (unsigned int)cmd.Op3.specval,
			(unsigned int)cmd.Op1.addr, (unsigned int)cmd.Op2.addr, (unsigned int)cmd.Op3.addr,
			(unsigned int)cmd.Op1.value, (unsigned int)cmd.Op2.value, (unsigned int)cmd.Op3.value,
			(unsigned int)cmd.Op1.reg, (unsigned int)cmd.Op2.reg, (unsigned int)cmd.Op3.reg,
			(unsigned int)cmd.Op1.dtyp, (unsigned int)cmd.Op2.dtyp, (unsigned int)cmd.Op3.dtyp,
			(unsigned int)cmd.Op1.flags, (unsigned int)cmd.Op2.flags, (unsigned int)cmd.Op3.flags);
		}
*/		
		
		// if found a function return point, then look above for return register
		if( !qstrcmp(mnem, "blr") )
		{
			is_in_return_point = true;
			//msg("%08X return point end\n", (unsigned int)ea);
		}
		
		// if a function is called, thenit is no longer in the return point
		else if( !qstrcmp(mnem, "bl") )
		{
			is_in_return_point = false;
			//msg("%08X return point start\n", (unsigned int)ea);
		}

		// look for possible return register
		else if( is_in_return_point &&
			!qstrcmp(mnem, "mr") &&
			cmd.Op1.type == o_reg &&
			cmd.Op2.type == o_reg &&
			cmd.Op1.reg == 3 )	// return value is in r3
		{
			int dst_reg = cmd.Op1.reg;
			int src_reg = cmd.Op2.reg;
			char canon[256];
			qsnprintf(canon, sizeof(canon), "%%r%d", src_reg);
			add_regvar(pFunc, start, end, canon, "ret", NULL);
			//msg("%08X return register\n", (unsigned int)ea);
		}
	}

	// analyse area to refresh any changes
	analyze_area(start, end);
	return 0;
}



/***************************************************************************************************
*
*	FUNCTION		PluginStartup
*
*	DESCRIPTION		Determines whether this plugin will work with the current database.
*
*					IDA will call this function only once. If this function returns PLUGIN_SKIP,
*					IDA will never load it again. If it returns PLUGIN_OK, IDA will unload the plugin
*					but remember that the plugin agreed to work with the database. The plugin will
*					be loaded again if the user invokes it by pressing the hotkey or selecting it
*					from the menu. After the second load, the plugin will stay in memory.
*
***************************************************************************************************/

int idaapi PluginStartup(void)
{
	// PPC Helper only works with PPC code :)
	if ( ph.id != PLFM_PPC )
		return PLUGIN_SKIP;
	
	// if PPC then this plugin is OK to use
	return PLUGIN_OK;
}



/***************************************************************************************************
*
*	FUNCTION		PluginShutdown
*
*	DESCRIPTION		IDA will call this function when the user asks to exit. This function is *not*
*					called in the case of emergency exits.
*
***************************************************************************************************/

void idaapi PluginShutdown(void)
{
	// any cleanup code that needs to be done on exit goes here
}



/***************************************************************************************************
*
*	FUNCTION		PluginMain
*
*	DESCRIPTION		This is the main function of plugin.
*					Param is an input arguement specified in plugins.cfg file.
*                   (The default is zero.)
*
***************************************************************************************************/

void idaapi PluginMain(int param)
{
	if(param == 0)
	{
		// convert the current function
		func_t* p_func = get_func(get_screen_ea());
		if(p_func == NULL)
		{
			msg("Not in a function, so can't run PPC Helper!\n");
			return;
		}
		PPCHelper_ConvertFunction(p_func);
	}
	else if(param == 1)
	{
		// convert all functions in the database
		
		// get address of first function
		func_t* p_func;
		ea_t ea = inf.minEA;
		p_func = get_func(ea);
		if( !p_func )
			p_func = get_next_func(ea);
		
		// process all function
		while( p_func )
		{
			// process function
			PPCHelper_ConvertFunction(p_func);
			
			// get next function
			p_func = get_next_func(p_func->startEA);
		}
	}
	else
	{
		msg("Unknown mode - Please set the mode of execution in the plugins.cfg file\n");
		return;
	}
}



/***************************************************************************************************
*
*	Strings required for IDA Pro's PLUGIN descriptor block
*
***************************************************************************************************/

const char G_PLUGIN_COMMENT[]	=	"PPC Helper";
const char G_PLUGIN_HELP[]		=	"This plugin assists in setting up common stack variables andf arguements for a function\n";
const char G_PLUGIN_NAME[]		=	"PPC Helper: Current Function";
const char G_PLUGIN_HOTKEY[]	=	"F11";



/***************************************************************************************************
*
*	This 'PLUGIN' data block is how IDA Pro interfaces with this plugin.
*
***************************************************************************************************/
plugin_t PLUGIN =
{
	// values
	IDP_INTERFACE_VERSION,
	0,						// plugin flags	
	
	// functions
	PluginStartup,			// initialize
	PluginShutdown,			// terminate. this pointer may be NULL.
	PluginMain,				// invoke plugin
	
	// strings
	(char*)G_PLUGIN_COMMENT,// long comment about the plugin (may appear on status line or as a hint)
	(char*)G_PLUGIN_HELP,	// multiline help about the plugin
	(char*)G_PLUGIN_NAME,	// the preferred short name of the plugin, used by menu system
	(char*)G_PLUGIN_HOTKEY	// the preferred hotkey to run the plugin
};


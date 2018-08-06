# Alternative 3.4.5M firmware

This directory contains alternative version of 3.4.5 firmware with all camera communications implemented via interrupts.

In a standard firmware, interrupts are used to wake up the main camera task only and the main logic is performed by the task at a standard level. This can be interrupted by CCD or CF card interrupts and for fast cameras (such as Phase One DF) cause message disruption. My firmmwares support for Phase One DF catered for this by relocating all message processing points that were affected in a places where there was no timing problem (message 54 that causes shutter early warning was moved to trigger at message 84 for example). 

However there was an alternative aproach which is implemented in this version of firmware. All the processing done in interrupts servicing REQ and SPI transfer. All camera communiction task functionality forming message replies and initiating SPI communications moved to SPI and REQ ISR. The main camera task code was simplified to essentially running a loop as follows: setup camera state, issue REQ when needed, wait for the message to be received and process the message. 

This firmware was tested and has the same functionality as 3.4.5M and offered here as alternative to try out and for technically minded to see how it could be done.
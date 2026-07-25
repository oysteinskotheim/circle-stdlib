#ifndef _circle_glue_h
#define _circle_glue_h

class CConsole;
class CNetSubSystem;
class CSerialDevice;

/**
 * Initialize stdio only for console I/O (stdin/stdout/stderr).
 * Must only be called once.
 */
void CGlueStdioInit (CConsole& rConsole);

/**
 * Initialize circle-newlib network subsystem with reference to Circle's
 * network subsystem.
 * Must only be called once.
 */
void CGlueNetworkInit (CNetSubSystem& rNetwork);

/**
 * BMC64: Initialize stdio to redirect to a serial device instead of the
 * console. Must only be called once.
 */
void CGlueStdioInit (CSerialDevice *serial);

#define MAX_BOOTSTAT_LINES 32
#define MAX_BOOTSTAT_FLEN 64

#define BOOTSTAT_WHAT_STAT 0
#define BOOTSTAT_WHAT_FAIL 1

void CGlueStdioInitBootStat (int num,
        int *mBootStatWhat,
        const char **mBootStateFile,
        int *mBootStatSize);

/**
 * Sets the partition to mount for the given volume.
 * volume string must match one of volumes defined in ffconf.h
 * if p == 5, ss will be used to force a start sector when finding the volume
 */
void CGlueStdioSetPartitionForVolume (const char* volume, int p, unsigned int ss);

#endif

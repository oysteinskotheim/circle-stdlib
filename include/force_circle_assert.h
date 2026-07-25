/*
 * force_circle_assert.h
 *
 * BMC64: force-included ahead of every C/C++ translation unit compiled
 * against circle-newlib, to work around circle/types.h's ASSERT_STATIC()
 * being silently undefined when a newlib-provided <assert.h> is found on
 * the include path before Circle's own one. A plain <assert.h> is still
 * subject to that same search-order shadowing (newlib's own libc/include
 * is searched before circle/include), so this references Circle's
 * assert.h directly by relative path instead, bypassing search order
 * entirely. Guarded against __ASSEMBLER__ so it doesn't get forced into
 * assembly (.S) files, which fail to parse the C declarations inside.
 */
#ifndef __ASSEMBLER__
#include "../libs/circle/include/assert.h"
#endif

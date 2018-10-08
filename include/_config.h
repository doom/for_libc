/*
** Created by doom on 08/10/18.
*/

#ifndef FOR_LIBC_CONFIG_H
#define FOR_LIBC_CONFIG_H

#ifdef __cplusplus
#define C_LINKAGE_BEGIN     extern "C" {
#define C_LINKAGE_END       }
#else
#define C_LINKAGE_BEGIN
#define C_LINKAGE_END
#endif /* !__cplusplus */

#endif /* !FOR_LIBC_CONFIG_H */

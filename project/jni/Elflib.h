#include <elf.h>
#include "Debugger.h"

extern u8 nm_get_external_sym_addr(const char*, const char*);
extern u8 nm_get_internal_sym_addr(const char*, const char*);
extern u8 nm_get_all_sym_addr(const char*, const char*);


// MultiEchoClap.h
// The three entry functions clap-wrapper links into every format.

#pragma once

bool tbme_entry_init (const char* pluginPath);
void tbme_entry_deinit();
const void* tbme_entry_get_factory (const char* factoryId);

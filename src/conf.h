/*
 * This file is part of the zlog Library.
 *
 * Copyright (C) 2011 by Hardy Simpson <HardySimpson1984@gmail.com>
 *
 * Licensed under the LGPL v2.1, see the file COPYING in base directory.
 */

#ifndef __zlog_conf_h
#define __zlog_conf_h

typedef struct zlog_conf_s {
	zc_sds file;
	int mtime;

	int strict_init;
	size_t buf_size;
	zc_sds rotate_lock_file;
	zc_sds default_format_line;
	unsigned int file_perms;
	size_t reload_conf;
	size_t fsync_write;

	zlog_rotater_t *rotater;
	zlog_format_t *default_format;

	zc_arraylist_t *levels;
	zc_arraylist_t *formats;
	zc_arraylist_t *rules;

	int time_spec_count; /* in all rules and formats, to create time caches */
} zlog_conf_t;

extern zlog_conf_t * zlog_env_conf;

zlog_conf_t *zlog_conf_new(const char *confpath);
void zlog_conf_del(zlog_conf_t * a_conf);
void zlog_conf_profile(zlog_conf_t * a_conf, int flag);

#endif

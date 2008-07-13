/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2008 Imendio AB
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __LM_RESOLVER_H__
#define __LM_RESOLVER_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define LM_TYPE_RESOLVER             (lm_resolver_get_type())
#define LM_RESOLVER(o)               (G_TYPE_CHECK_INSTANCE_CAST((o), LM_TYPE_RESOLVER, LmResolver))
#define LM_IS_RESOLVER(o)            (G_TYPE_CHECK_INSTANCE_TYPE((o), LM_TYPE_RESOLVER))
#define LM_RESOLVER_GET_IFACE(o)     (G_TYPE_INSTANCE_GET_INTERFACE((o), LM_TYPE_RESOLVER, LmResolverIface))

typedef struct _LmResolver      LmResolver;
typedef struct _LmResolverIface LmResolverIface;

struct _LmResolverIface {
	GTypeInterface parent;

	/* <vtable> */
        void     (*lookup_host)       (LmResolver  *resolver,
                                       const gchar *host);
        void     (*lookup_srv)        (LmResolver  *resolver,
                                       const gchar *domain,
                                       const gchar *srv);
        void     (*cancel)            (LmResolver  *resolver);
};

typedef void  (*LmResolverCallback)  (LmResolver  *resolver,
                                      guint        status_code,
                                      gpointer     user_data);

GType          lm_resolver_get_type          (void);

LmResolver *   lm_resolver_new               (LmResolverCallback  callback,
                                              gpointer            user_data);
void           lm_resolver_lookup_host       (LmResolver         *resolver,
                                              const gchar        *host);
void           lm_resolver_lookup_srv        (LmResolver         *resolver,
                                              const gchar        *domain,
                                              const gchar        *srv);
void           lm_resolver_cancel            (LmResolver         *resolver);

G_END_DECLS

#endif /* __LM_RESOLVER_H__ */

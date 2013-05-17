/* GStreamer
 * Copyright (C) <2013> Wim Taymans <wim.taymans@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_VIDEO_CHROMA_H__
#define __GST_VIDEO_CHROMA_H__

#include <gst/gst.h>

G_BEGIN_DECLS

/**
 * GstVideoChromaSite:
 * @GST_VIDEO_CHROMA_SITE_UNKNOWN: unknown cositing
 * @GST_VIDEO_CHROMA_SITE_NONE: no cositing
 * @GST_VIDEO_CHROMA_SITE_H_COSITED: chroma is horizontally cosited
 * @GST_VIDEO_CHROMA_SITE_V_COSITED: chroma is vertically cosited
 * @GST_VIDEO_CHROMA_SITE_ALT_LINE: choma samples are sited on alternate lines
 * @GST_VIDEO_CHROMA_SITE_COSITED: chroma samples cosited with luma samples
 * @GST_VIDEO_CHROMA_SITE_JPEG: jpeg style cositing, also for mpeg1 and mjpeg
 * @GST_VIDEO_CHROMA_SITE_MPEG2: mpeg2 style cositing
 * @GST_VIDEO_CHROMA_SITE_DV: DV style cositing
 *
 * Various Chroma sitings.
 */
typedef enum {
  GST_VIDEO_CHROMA_SITE_UNKNOWN   =  0,
  GST_VIDEO_CHROMA_SITE_NONE      = (1 << 0),
  GST_VIDEO_CHROMA_SITE_H_COSITED = (1 << 1),
  GST_VIDEO_CHROMA_SITE_V_COSITED = (1 << 2),
  GST_VIDEO_CHROMA_SITE_ALT_LINE  = (1 << 3),
  /* some common chroma cositing */
  GST_VIDEO_CHROMA_SITE_COSITED   = (GST_VIDEO_CHROMA_SITE_H_COSITED | GST_VIDEO_CHROMA_SITE_V_COSITED),
  GST_VIDEO_CHROMA_SITE_JPEG      = (GST_VIDEO_CHROMA_SITE_NONE),
  GST_VIDEO_CHROMA_SITE_MPEG2     = (GST_VIDEO_CHROMA_SITE_H_COSITED),
  GST_VIDEO_CHROMA_SITE_DV        = (GST_VIDEO_CHROMA_SITE_COSITED | GST_VIDEO_CHROMA_SITE_ALT_LINE),
} GstVideoChromaSite;

GstVideoChromaSite    gst_video_chroma_from_string   (const gchar * s);
const gchar *         gst_video_chroma_to_string     (GstVideoChromaSite site);

G_END_DECLS

#endif /* __GST_VIDEO_CHROMA_H__ */
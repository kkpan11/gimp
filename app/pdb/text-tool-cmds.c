/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995-2003 Spencer Kimball and Peter Mattis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl. */

#include "config.h"

#include "stamp-pdbgen.h"

#include <gegl.h>

#include <gdk-pixbuf/gdk-pixbuf.h>

#include "libgimpbase/gimpbase.h"

#include "libgimpbase/gimpbase.h"

#include "pdb-types.h"

#include "core/gimpdrawable.h"
#include "core/gimpimage.h"
#include "core/gimplayer.h"
#include "core/gimpparamspecs.h"
#include "text/gimpfont.h"
#include "text/gimptext-compat.h"

#include "gimppdb.h"
#include "gimppdb-utils.h"
#include "gimpprocedure.h"
#include "internal-procs.h"


static GimpValueArray *
text_font_invoker (GimpProcedure         *procedure,
                   Gimp                  *gimp,
                   GimpContext           *context,
                   GimpProgress          *progress,
                   const GimpValueArray  *args,
                   GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  GimpImage *image;
  GimpDrawable *drawable;
  gdouble x;
  gdouble y;
  const gchar *text;
  gint border;
  gboolean antialias;
  gdouble size;
  GimpFont *font;
  GimpLayer *text_layer = NULL;

  image = g_value_get_object (gimp_value_array_index (args, 0));
  drawable = g_value_get_object (gimp_value_array_index (args, 1));
  x = g_value_get_double (gimp_value_array_index (args, 2));
  y = g_value_get_double (gimp_value_array_index (args, 3));
  text = g_value_get_string (gimp_value_array_index (args, 4));
  border = g_value_get_int (gimp_value_array_index (args, 5));
  antialias = g_value_get_boolean (gimp_value_array_index (args, 6));
  size = g_value_get_double (gimp_value_array_index (args, 7));
  font = g_value_get_object (gimp_value_array_index (args, 8));

  if (success)
    {
      if (drawable &&
          (! gimp_pdb_item_is_attached (GIMP_ITEM (drawable), image,
                                        GIMP_PDB_ITEM_CONTENT, error) ||
           ! gimp_pdb_item_is_not_group (GIMP_ITEM (drawable), error)))
        success = FALSE;

      if (success)
        text_layer = text_render (image, drawable, context,
                                  x, y, font, size, text,
                                  border, antialias);
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_set_object (gimp_value_array_index (return_vals, 1), text_layer);

  return return_vals;
}

static GimpValueArray *
text_get_extents_font_invoker (GimpProcedure         *procedure,
                               Gimp                  *gimp,
                               GimpContext           *context,
                               GimpProgress          *progress,
                               const GimpValueArray  *args,
                               GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  const gchar *text;
  gdouble size;
  GimpFont *font;
  gint width = 0;
  gint height = 0;
  gint ascent = 0;
  gint descent = 0;

  text = g_value_get_string (gimp_value_array_index (args, 0));
  size = g_value_get_double (gimp_value_array_index (args, 1));
  font = g_value_get_object (gimp_value_array_index (args, 2));

  if (success)
    {
      success = text_get_extents (gimp,
                                  font, size, text,
                                  &width, &height,
                                  &ascent, &descent);
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    {
      g_value_set_int (gimp_value_array_index (return_vals, 1), width);
      g_value_set_int (gimp_value_array_index (return_vals, 2), height);
      g_value_set_int (gimp_value_array_index (return_vals, 3), ascent);
      g_value_set_int (gimp_value_array_index (return_vals, 4), descent);
    }

  return return_vals;
}

void
register_text_tool_procs (GimpPDB *pdb)
{
  GimpProcedure *procedure;

  /*
   * gimp-text-font
   */
  procedure = gimp_procedure_new (text_font_invoker, FALSE);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-text-font");
  gimp_procedure_set_static_help (procedure,
                                  "Add text at the specified location as a floating selection or a new layer.",
                                  "The x and y parameters together control the placement of the new text by specifying the upper left corner of the text bounding box. If the specified drawable parameter is valid, the text will be created as a floating selection attached to the drawable. If the drawable parameter is not valid (%NULL), the text will appear as a new layer. Finally, a border can be specified around the final rendered text. The border is measured in pixels.\n"
                                  "The size is always in pixels. If you need to display a font in points, divide the size in points by 72.0 and multiply it by the image's vertical resolution.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Martin Edlman & Sven Neumann",
                                         "Spencer Kimball & Peter Mattis",
                                         "1998- 2001");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_image ("image",
                                                      "image",
                                                      "The image",
                                                      FALSE,
                                                      GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_drawable ("drawable",
                                                         "drawable",
                                                         "The affected drawable: (%NULL for a new text layer)",
                                                         TRUE,
                                                         GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_double ("x",
                                                    "x",
                                                    "The x coordinate for the left of the text bounding box",
                                                    -G_MAXDOUBLE, G_MAXDOUBLE, 0,
                                                    GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_double ("y",
                                                    "y",
                                                    "The y coordinate for the top of the text bounding box",
                                                    -G_MAXDOUBLE, G_MAXDOUBLE, 0,
                                                    GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("text",
                                                       "text",
                                                       "The text to generate (in UTF-8 encoding)",
                                                       FALSE, FALSE, FALSE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_int ("border",
                                                 "border",
                                                 "The size of the border",
                                                 -1, G_MAXINT32, -1,
                                                 GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_boolean ("antialias",
                                                     "antialias",
                                                     "Antialiasing",
                                                     FALSE,
                                                     GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_double ("size",
                                                    "size",
                                                    "The size of text in pixels",
                                                    0, G_MAXDOUBLE, 0,
                                                    GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_font ("font",
                                                     "font",
                                                     "The font",
                                                     FALSE,
                                                     NULL,
                                                     FALSE,
                                                     GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   gimp_param_spec_layer ("text-layer",
                                                          "text layer",
                                                          "The new text layer or %NULL if no layer was created.",
                                                          TRUE,
                                                          GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-text-get-extents-font
   */
  procedure = gimp_procedure_new (text_get_extents_font_invoker, FALSE);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-text-get-extents-font");
  gimp_procedure_set_static_help (procedure,
                                  "Get extents of the bounding box for the specified text.",
                                  "This tool returns the width and height of a bounding box for the specified text rendered with the specified font information. Ascent and descent of the glyph extents are returned as well.\n"
                                  "The ascent is the distance from the baseline to the highest point of the character. This is positive if the glyph ascends above the baseline. The descent is the distance from the baseline to the lowest point of the character. This is positive if the glyph descends below the baseline.\n"
                                  "The size is always in pixels. If you need to set a font in points, divide the size in points by 72.0 and multiply it by the vertical resolution of the image you are taking into account.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Martin Edlman & Sven Neumann",
                                         "Spencer Kimball & Peter Mattis",
                                         "1998- 2001");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("text",
                                                       "text",
                                                       "The text to generate (in UTF-8 encoding)",
                                                       FALSE, FALSE, FALSE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_double ("size",
                                                    "size",
                                                    "The size of text in either pixels or points",
                                                    0, G_MAXDOUBLE, 0,
                                                    GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_font ("font",
                                                     "font",
                                                     "The name of the font",
                                                     FALSE,
                                                     NULL,
                                                     FALSE,
                                                     GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_int ("width",
                                                     "width",
                                                     "The width of the glyph extents",
                                                     G_MININT32, G_MAXINT32, 0,
                                                     GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_int ("height",
                                                     "height",
                                                     "The height of the glyph extents",
                                                     G_MININT32, G_MAXINT32, 0,
                                                     GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_int ("ascent",
                                                     "ascent",
                                                     "The ascent of the glyph extents",
                                                     G_MININT32, G_MAXINT32, 0,
                                                     GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_int ("descent",
                                                     "descent",
                                                     "The descent of the glyph extents",
                                                     G_MININT32, G_MAXINT32, 0,
                                                     GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);
}

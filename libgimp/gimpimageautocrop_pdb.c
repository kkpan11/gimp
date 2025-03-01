/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimpimageautocrop_pdb.c
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl */

#include "config.h"

#include "stamp-pdbgen.h"

#include "gimp.h"


/**
 * SECTION: gimpimageautocrop
 * @title: gimpimageautocrop
 * @short_description: Functions that crop images or layers.
 *
 * Functions that crop images or layers.
 **/


/**
 * gimp_image_autocrop:
 * @image: Input image).
 * @drawable: (nullable): Input drawable.
 *
 * Remove empty borders from the image
 *
 * Remove empty borders from the @image based on empty borders of the
 * input @drawable.
 *
 * The input drawable serves as a base for detecting cropping extents
 * (transparency or background color).
 * With a %NULL input drawable, the image itself will serve as a base
 * for detecting cropping extents.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_image_autocrop (GimpImage    *image,
                     GimpDrawable *drawable)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          GIMP_TYPE_DRAWABLE, drawable,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-image-autocrop",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_image_autocrop_selected_layers:
 * @image: Input image.
 * @drawable: (nullable): Input drawable.
 *
 * Crop the selected layers based on empty borders of the input
 * drawable
 *
 * Crop the selected layers of the input @image based on empty borders
 * of the input @drawable.
 * The input drawable serves as a base for detecting cropping extents
 * (transparency or background color), and is not necessarily among the
 * cropped layers (the current selected layers).
 * With a %NULL input drawable, the image itself will serve as a base
 * for detecting cropping extents.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_image_autocrop_selected_layers (GimpImage    *image,
                                     GimpDrawable *drawable)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          GIMP_TYPE_DRAWABLE, drawable,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-image-autocrop-selected-layers",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

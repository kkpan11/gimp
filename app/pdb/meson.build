libapppdb_sources = [
  'gimp-pdb-compat.c',
  'gimppdb-query.c',
  'gimppdb-utils.c',
  'gimppdb.c',
  'gimppdbcontext.c',
  'gimppdberror.c',
  'gimpprocedure.c',
]
libappinternalprocs_sources = [
  'brush-cmds.c',
  'brush-select-cmds.c',
  'brushes-cmds.c',
  'buffer-cmds.c',
  'channel-cmds.c',
  'context-cmds.c',
  'debug-cmds.c',
  'display-cmds.c',
  'drawable-cmds.c',
  'drawable-color-cmds.c',
  'drawable-edit-cmds.c',
  'drawable-filter-cmds.c',
  'drawable-select-cmds.c',
  'dynamics-cmds.c',
  'edit-cmds.c',
  'file-cmds.c',
  'floating-sel-cmds.c',
  'font-cmds.c',
  'font-select-cmds.c',
  'fonts-cmds.c',
  'gimp-cmds.c',
  'gimprc-cmds.c',
  'gradient-cmds.c',
  'gradient-select-cmds.c',
  'gradients-cmds.c',
  'group-layer-cmds.c',
  'help-cmds.c',
  'image-cmds.c',
  'image-autocrop-cmds.c',
  'image-color-profile-cmds.c',
  'image-convert-cmds.c',
  'image-grid-cmds.c',
  'image-guides-cmds.c',
  'image-sample-points-cmds.c',
  'image-select-cmds.c',
  'image-transform-cmds.c',
  'image-undo-cmds.c',
  'internal-procs.c',
  'item-cmds.c',
  'item-transform-cmds.c',
  'layer-cmds.c',
  'message-cmds.c',
  'paint-tools-cmds.c',
  'palette-cmds.c',
  'palette-select-cmds.c',
  'palettes-cmds.c',
  'path-cmds.c',
  'pattern-cmds.c',
  'pattern-select-cmds.c',
  'patterns-cmds.c',
  'pdb-cmds.c',
  'plug-in-cmds.c',
  'progress-cmds.c',
  'resource-cmds.c',
  'selection-cmds.c',
  'text-layer-cmds.c',
  'text-tool-cmds.c',
  'unit-cmds.c',
]

libapppdb = static_library('apppdb',
  libapppdb_sources,
  include_directories: [ rootInclude, rootAppInclude, ],
  c_args: '-DG_LOG_DOMAIN="Gimp-PDB"',
  dependencies: [
    cairo, gegl, gdk_pixbuf,
  ],
)


libappinternalprocs = static_library('appinternalprocs',
  libappinternalprocs_sources,
  include_directories: [ rootInclude, rootAppInclude, ],
  c_args: '-DG_LOG_DOMAIN="Gimp-PDB"',
  dependencies: [
    cairo, gegl, gdk_pixbuf, pangocairo, pango,
  ],
  sources: [
    pdbgen
  ],
)

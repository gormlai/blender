/* SPDX-FileCopyrightText: 2020 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

/** \file
 * \ingroup gpu
 */

#pragma once

#include "MEM_guardedalloc.h"

#include "GPU_drawlist.hh"

namespace blender::gpu {

/**
 * Implementation of Multi Draw Indirect.
 * Base class which is then specialized for each implementation (GL, VK, ...).
 */
class DrawList {
 public:
  virtual ~DrawList() = default;

  virtual void append(Batch *batch, int i_first, int i_count) = 0;
  virtual void submit() = 0;
};

/* Syntactic sugar. */
static inline GPUDrawList *wrap(DrawList *vert)
{
  return reinterpret_cast<GPUDrawList *>(vert);
}
static inline DrawList *unwrap(GPUDrawList *vert)
{
  return reinterpret_cast<DrawList *>(vert);
}
static inline const DrawList *unwrap(const GPUDrawList *vert)
{
  return reinterpret_cast<const DrawList *>(vert);
}

}  // namespace blender::gpu

//===- DocGenUtilities.h - MLIR doc gen utilities ---------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines common utilities for generating documents from tablegen
// structures.
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_TOOLS_MLIRTBLGEN_DOCGENUTILITIES_H_
#define MLIR_TOOLS_MLIRTBLGEN_DOCGENUTILITIES_H_

#include "llvm/ADT/StringRef.h"

namespace llvm {
class raw_ostream;
} // namespace llvm

namespace mlir {
namespace tblgen {

// Emit the summary. To avoid confusion, the summary is styled differently from
// the description.
void emitSummary(llvm::StringRef summary, llvm::raw_ostream &os);

// Emit the description by aligning the text to the left per line (e.g.
// removing the minimum indentation across the block).
//
// This expects that the description in the tablegen file is already formatted
// in a way the user wanted but has some additional indenting due to being
// nested.
void emitDescription(llvm::StringRef description, llvm::raw_ostream &os);

// Emit the description as a C++ comment while realigning it.
void emitDescriptionComment(llvm::StringRef description, llvm::raw_ostream &os,
                            llvm::StringRef prefix = "");

} // namespace tblgen
} // namespace mlir

#endif // MLIR_TOOLS_MLIRTBLGEN_DOCGENUTILITIES_H_

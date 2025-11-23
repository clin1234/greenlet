#ifndef PYGREENLET_HPP
#define PYGREENLET_HPP


#include "greenlet.h"
#include "greenlet_compiler_compat.hpp"
#include "greenlet_refs.hpp"


using greenlet::refs::OwnedGreenlet;
using greenlet::refs::BorrowedGreenlet;
using greenlet::refs::BorrowedObject;;
using greenlet::refs::OwnedObject;
using greenlet::refs::PyErrPieces;


// XXX: These doesn't really belong here, it's not a Python slot.
static OwnedObject internal_green_throw(BorrowedGreenlet self, PyErrPieces& err_pieces);

static PyGreenlet* green_new(PyTypeObject* type, PyObject* UNUSED(args), PyObject* UNUSED(kwds));
static constexpr int green_clear(PyGreenlet* self);
static constexpr int green_init(PyGreenlet* self, PyObject* args, PyObject* kwargs);
static constexpr int green_setparent(PyGreenlet* self, PyObject* nparent, void* UNUSED(context));
static constexpr int green_setrun(PyGreenlet* self, PyObject* nrun, void* UNUSED(context));
static constexpr int green_traverse(PyGreenlet* self, visitproc visit, void* arg);
static constexpr void green_dealloc(PyGreenlet* self);
constexpr static PyObject* green_getparent(PyGreenlet* self, void* UNUSED(context));

static constexpr int green_is_gc(PyObject* self);
constexpr static PyObject* green_getdead(PyGreenlet* self, void* UNUSED(context));
constexpr static PyObject* green_getrun(PyGreenlet* self, void* UNUSED(context));
static constexpr int green_setcontext(PyGreenlet* self, PyObject* nctx, void* UNUSED(context));
constexpr static PyObject* green_getframe(PyGreenlet* self, void* UNUSED(context));
constexpr static PyObject* green_repr(PyGreenlet* self);
#endif

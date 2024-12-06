#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "integrator.hpp" 

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    m.doc() = "Python bindings for HarmonicOscillator using Pybind11";  // Module docstring

    // Bind the HarmonicOscillator class
    py::class_<HarmonicOscillator>(m, "HarmonicOscillator")
        .def(py::init<double, double>(), 
             py::arg("mass"), 
             py::arg("frequency"), 
             "Constructor for HarmonicOscillator with mass and frequency.")
        .def("energy", &HarmonicOscillator::energy, 
             "Compute the energy of the harmonic oscillator.")
        .def("step", &HarmonicOscillator::step, 
             py::arg("time_step"), 
             "Advance the oscillator by the given time step.");
}

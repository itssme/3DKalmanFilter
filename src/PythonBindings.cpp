#include <pybind11/pybind11.h>
#include "KalmanFilter3D.h"

namespace py = pybind11;

PYBIND11_MODULE(KalmanFilter3D, m) {
    m.doc() = "pybind11 bindings for KalmanFilter3D class";

    py::class_<KalmanFilter3D>(m, "KalmanFilter3D")
        .def(py::init<double, double , double>())
        .def("predict", &KalmanFilter3D::predict, "Predicts the next state of the system.")
        .def("update", &KalmanFilter3D::update, py::arg("z"), "Updates the state with a new measurement.")
        .def("getState", &KalmanFilter3D::getState, py::arg("state"), "Gets the current state.");
}


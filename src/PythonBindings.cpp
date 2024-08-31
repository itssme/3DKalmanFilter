#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "KalmanFilter3D.h"

namespace py = pybind11;

PYBIND11_MODULE(KalmanFilter3D, m) {
    m.doc() = "pybind11 bindings for KalmanFilter3D class";

    py::class_<KalmanFilter3D>(m, "KalmanFilter3D")
        .def(py::init<double, double, double>(), py::arg("dt"), py::arg("process_noise_std"), py::arg("measurement_noise_std"))
        .def("predict", &KalmanFilter3D::predict)
        .def("update", [](KalmanFilter3D &kf, py::array_t<double> z) {
            if (z.size() != 3) {
                throw std::runtime_error("Input measurement must be an array of size 3.");
            }
            py::buffer_info z_info = z.request();
            double* z_ptr = static_cast<double*>(z_info.ptr);
            kf.update(z_ptr);
        })
        .def("get_state", [](const KalmanFilter3D &kf) {
            double state[6];
            kf.getState(state);
            return py::array_t<double>(6, state);
        });
}

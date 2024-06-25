// File: T82_eigen.cpp
#include <T82.eigen.hpp> // EigenTest::Bar
#include <T82.eigen.hpp> // EigenTest::foo_eigen_argument_and_return_function
#include <T82.eigen.hpp> // EigenTest::foo_eigen_argument_function
#include <T82.eigen.hpp> // EigenTest::foo_eigen_return_function
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <pybind11/eigen.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T82_eigen(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// EigenTest::foo_eigen_argument_function(const class Eigen::Matrix<float, 3, 3> &) file:T82.eigen.hpp line:13
	M("EigenTest").def("foo_eigen_argument_function", (void (*)(const class Eigen::Matrix<float, 3, 3> &)) &EigenTest::foo_eigen_argument_function<float>, "C++: EigenTest::foo_eigen_argument_function(const class Eigen::Matrix<float, 3, 3> &) --> void", pybind11::arg("m"));

	// EigenTest::foo_eigen_argument_function(const class Eigen::Matrix<double, 3, 3> &) file:T82.eigen.hpp line:13
	M("EigenTest").def("foo_eigen_argument_function", (void (*)(const class Eigen::Matrix<double, 3, 3> &)) &EigenTest::foo_eigen_argument_function<double>, "C++: EigenTest::foo_eigen_argument_function(const class Eigen::Matrix<double, 3, 3> &) --> void", pybind11::arg("m"));

	// EigenTest::foo_eigen_return_function() file:T82.eigen.hpp line:20
	M("EigenTest").def("foo_eigen_return_function", (class Eigen::Matrix<float, 3, 3> (*)()) &EigenTest::foo_eigen_return_function<float>, "C++: EigenTest::foo_eigen_return_function() --> class Eigen::Matrix<float, 3, 3>");

	// EigenTest::foo_eigen_return_function() file:T82.eigen.hpp line:20
	M("EigenTest").def("foo_eigen_return_function", (class Eigen::Matrix<double, 3, 3> (*)()) &EigenTest::foo_eigen_return_function<double>, "C++: EigenTest::foo_eigen_return_function() --> class Eigen::Matrix<double, 3, 3>");

	// EigenTest::foo_eigen_argument_and_return_function(const class Eigen::Matrix<float, 3, 3> &) file:T82.eigen.hpp line:28
	M("EigenTest").def("foo_eigen_argument_and_return_function", (class Eigen::Matrix<float, 3, 3> (*)(const class Eigen::Matrix<float, 3, 3> &)) &EigenTest::foo_eigen_argument_and_return_function<float>, "C++: EigenTest::foo_eigen_argument_and_return_function(const class Eigen::Matrix<float, 3, 3> &) --> class Eigen::Matrix<float, 3, 3>", pybind11::arg("m"));

	// EigenTest::foo_eigen_argument_and_return_function(const class Eigen::Matrix<double, 3, 3> &) file:T82.eigen.hpp line:28
	M("EigenTest").def("foo_eigen_argument_and_return_function", (class Eigen::Matrix<double, 3, 3> (*)(const class Eigen::Matrix<double, 3, 3> &)) &EigenTest::foo_eigen_argument_and_return_function<double>, "C++: EigenTest::foo_eigen_argument_and_return_function(const class Eigen::Matrix<double, 3, 3> &) --> class Eigen::Matrix<double, 3, 3>", pybind11::arg("m"));

	{ // EigenTest::Bar file:T82.eigen.hpp line:49
		pybind11::class_<EigenTest::Bar<float>, std::shared_ptr<EigenTest::Bar<float>>> cl(M("EigenTest"), "Bar_float_t", "");
		cl.def( pybind11::init( [](){ return new EigenTest::Bar<float>(); } ) );
		cl.def( pybind11::init( [](EigenTest::Bar<float> const &o){ return new EigenTest::Bar<float>(o); } ) );
		cl.def_readwrite("eigen_property", &EigenTest::Bar<float>::eigen_property);
		cl.def("foo_eigen_argument_method", (void (EigenTest::Bar<float>::*)(const class Eigen::Matrix<float, 3, 3> &)) &EigenTest::Bar<float>::foo_eigen_argument_method, "C++: EigenTest::Bar<float>::foo_eigen_argument_method(const class Eigen::Matrix<float, 3, 3> &) --> void", pybind11::arg("m"));
		cl.def("foo_eigen_return_method", (class Eigen::Matrix<float, 3, 3> (EigenTest::Bar<float>::*)()) &EigenTest::Bar<float>::foo_eigen_return_method, "C++: EigenTest::Bar<float>::foo_eigen_return_method() --> class Eigen::Matrix<float, 3, 3>");
		cl.def("foo_eigen_argument_and_return_method", (class Eigen::Matrix<float, 3, 3> (EigenTest::Bar<float>::*)(const class Eigen::Matrix<float, 3, 3> &)) &EigenTest::Bar<float>::foo_eigen_argument_and_return_method, "C++: EigenTest::Bar<float>::foo_eigen_argument_and_return_method(const class Eigen::Matrix<float, 3, 3> &) --> class Eigen::Matrix<float, 3, 3>", pybind11::arg("m"));
		cl.def_static("foo_eigen_argument_method_static", (void (*)(const class Eigen::Matrix<float, 3, 3> &)) &EigenTest::Bar<float>::foo_eigen_argument_method_static, "C++: EigenTest::Bar<float>::foo_eigen_argument_method_static(const class Eigen::Matrix<float, 3, 3> &) --> void", pybind11::arg("m"));
		cl.def_static("foo_eigen_return_method_static", (class Eigen::Matrix<float, 3, 3> (*)()) &EigenTest::Bar<float>::foo_eigen_return_method_static, "C++: EigenTest::Bar<float>::foo_eigen_return_method_static() --> class Eigen::Matrix<float, 3, 3>");
		cl.def_static("foo_eigen_argument_and_return_method_static", (class Eigen::Matrix<float, 3, 3> (*)(const class Eigen::Matrix<float, 3, 3> &)) &EigenTest::Bar<float>::foo_eigen_argument_and_return_method_static, "C++: EigenTest::Bar<float>::foo_eigen_argument_and_return_method_static(const class Eigen::Matrix<float, 3, 3> &) --> class Eigen::Matrix<float, 3, 3>", pybind11::arg("m"));
		cl.def("assign", (class EigenTest::Bar<float> & (EigenTest::Bar<float>::*)(const class EigenTest::Bar<float> &)) &EigenTest::Bar<float>::operator=, "C++: EigenTest::Bar<float>::operator=(const class EigenTest::Bar<float> &) --> class EigenTest::Bar<float> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // EigenTest::Bar file:T82.eigen.hpp line:50
		pybind11::class_<EigenTest::Bar<double>, std::shared_ptr<EigenTest::Bar<double>>> cl(M("EigenTest"), "Bar_double_t", "");
		cl.def( pybind11::init( [](){ return new EigenTest::Bar<double>(); } ) );
		cl.def( pybind11::init( [](EigenTest::Bar<double> const &o){ return new EigenTest::Bar<double>(o); } ) );
		cl.def_readwrite("eigen_property", &EigenTest::Bar<double>::eigen_property);
		cl.def("foo_eigen_argument_method", (void (EigenTest::Bar<double>::*)(const class Eigen::Matrix<double, 3, 3> &)) &EigenTest::Bar<double>::foo_eigen_argument_method, "C++: EigenTest::Bar<double>::foo_eigen_argument_method(const class Eigen::Matrix<double, 3, 3> &) --> void", pybind11::arg("m"));
		cl.def("foo_eigen_return_method", (class Eigen::Matrix<double, 3, 3> (EigenTest::Bar<double>::*)()) &EigenTest::Bar<double>::foo_eigen_return_method, "C++: EigenTest::Bar<double>::foo_eigen_return_method() --> class Eigen::Matrix<double, 3, 3>");
		cl.def("foo_eigen_argument_and_return_method", (class Eigen::Matrix<double, 3, 3> (EigenTest::Bar<double>::*)(const class Eigen::Matrix<double, 3, 3> &)) &EigenTest::Bar<double>::foo_eigen_argument_and_return_method, "C++: EigenTest::Bar<double>::foo_eigen_argument_and_return_method(const class Eigen::Matrix<double, 3, 3> &) --> class Eigen::Matrix<double, 3, 3>", pybind11::arg("m"));
		cl.def_static("foo_eigen_argument_method_static", (void (*)(const class Eigen::Matrix<double, 3, 3> &)) &EigenTest::Bar<double>::foo_eigen_argument_method_static, "C++: EigenTest::Bar<double>::foo_eigen_argument_method_static(const class Eigen::Matrix<double, 3, 3> &) --> void", pybind11::arg("m"));
		cl.def_static("foo_eigen_return_method_static", (class Eigen::Matrix<double, 3, 3> (*)()) &EigenTest::Bar<double>::foo_eigen_return_method_static, "C++: EigenTest::Bar<double>::foo_eigen_return_method_static() --> class Eigen::Matrix<double, 3, 3>");
		cl.def_static("foo_eigen_argument_and_return_method_static", (class Eigen::Matrix<double, 3, 3> (*)(const class Eigen::Matrix<double, 3, 3> &)) &EigenTest::Bar<double>::foo_eigen_argument_and_return_method_static, "C++: EigenTest::Bar<double>::foo_eigen_argument_and_return_method_static(const class Eigen::Matrix<double, 3, 3> &) --> class Eigen::Matrix<double, 3, 3>", pybind11::arg("m"));
		cl.def("assign", (class EigenTest::Bar<double> & (EigenTest::Bar<double>::*)(const class EigenTest::Bar<double> &)) &EigenTest::Bar<double>::operator=, "C++: EigenTest::Bar<double>::operator=(const class EigenTest::Bar<double> &) --> class EigenTest::Bar<double> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

void bind_T82_eigen(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T82_eigen, root_module) {
	root_module.doc() = "T82_eigen module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	static std::vector<std::string> const reserved_python_words {"nonlocal", "global", };

	auto mangle_namespace_name(
		[](std::string const &ns) -> std::string {
			if ( std::find(reserved_python_words.begin(), reserved_python_words.end(), ns) == reserved_python_words.end() ) return ns;
			return ns+'_';
		}
	);

	std::vector< std::pair<std::string, std::string> > sub_modules {
		{"", "EigenTest"},
	};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T82_eigen(M);

}

// Source list file: /mnt/c/Users/hailin/Desktop/binder/cmake-build-debug-wsl/test//T82_eigen.sources
// T82_eigen.cpp
// T82_eigen.cpp

// Modules list file: /mnt/c/Users/hailin/Desktop/binder/cmake-build-debug-wsl/test//T82_eigen.modules
// EigenTest

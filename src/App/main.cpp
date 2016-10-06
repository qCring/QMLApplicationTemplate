#include <stdlib.h>

#include "appInstance.hpp"

auto main(int argc, char *argv[]) -> int {
    return app::Instance::Execute(argc, argv);
}

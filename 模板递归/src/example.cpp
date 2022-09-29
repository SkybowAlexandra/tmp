#include "Row.h"

int main(void)
{
    Row<int, 3> row;
    row[2][2][3] = 12;
    std::cout << row[2][2][3] << std::endl;
    return 0;
}
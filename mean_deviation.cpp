#include "mean_deviation.hpp"

std::vector<double> inputSample(int rows, int columns)
{

    std::vector<double> storage(rows * columns);

    for (int idx= 0; idx < rows * columns; ++idx)
    {
        std::cin >> storage[idx];
    }

    // for (int jdx = 0; jdx < rows * columns; ++jdx)
    // {
    //     std::cout << storage[jdx] << " ";

    // }
    return storage;
}

int mean(std::vector<double> vect, int length) 
{
    double result = 0;
    for (int idx = 0; idx < length; ++idx) 
    {
        result += vect[idx];
    }
    
    return result / length;
}

double dispertion(std::vector<double> vect, double mean, int length) 
{
    double result = 0;

    for (int idx = 0; idx < length; ++idx)
    {
        result += ((vect[idx] - mean) * (vect[idx] - mean));
    }
    result /= length;
    result = std::sqrt(result);
    return result;
}


double mean_deviation(std::vector<double> storage, int rws, int col) 
{
    double mean_value = mean(storage, rws * col);
    double mean_deviation_value = dispertion(storage, mean_value, rws * col);

    // std::cout << mean_deviation_value << "\n";
    return mean_deviation_value;
}

int main() 
{
    int rows, columns;
    std::cout << "Input rows and columns" << "\n";
    std::cin >> rows >> columns;
    std::vector<double> storage = inputSample(rows, columns);

    double result = mean_deviation(storage, rows, columns);
    std::cout << result << "\n";
}
 
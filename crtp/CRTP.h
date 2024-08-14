//CRTP.h
#include <iostream>

// --- overhead about virtual function for high-performance computing

//example vector 

// -- dynamic_vector.h

#include <numeric>
#include <vector>
#include <iterator>
#include <iosfwd>

template<typename T>
class DynamicVector
{
public:
    using value_type = T;
    using iterator = typename std::vector<T>::iterator;

};

template<typename T>
class DenseVector
{
public:
    virtual ~DenseVector() = default;
    virtual size_t size() const = 0;

    virtual T& operator[](size_t index) = 0;
    virtual T const& operator[](size_t index) const = 0;
};

template<typename T>
std::ostream& operator << (std::ostream& os, DenseVector<T> const& vector)
{

}


//CRTP for static mixin classes

//StrongType.h
#include <utility>

template<typename T, typename Tag>
struct StrongType
{
public:
    using value_type = T;

    explicit StrongType(T const& value)
    : value_(value)
    {
    }

    T& get() {return value_;}
    T const& get() const {return value_;}
private:
    T value_;
};

//distance
template<typename T>
using Meter = StrongType<T, struct MeterTag>;

template<typename T>
using Kilometer = StrongType<T, struct KilometerTag>;


//person
using Surname = StrongType<std::string, struct SurnameTag>;

void testCRTP()
{
    auto const m1 = Meter<long>{120};
}

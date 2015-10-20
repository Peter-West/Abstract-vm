#ifndef VMSTACK_HPP
#define VMSTACK_HPP

#include <stack>

template <typename T>
class VmStack : public std::stack<T>
{
    private:
        typedef std::stack<T> base;

    public:
    VmStack(void) {}
    ~VmStack(void) {}
    VmStack(VmStack const & o): base(o) {}

    typedef typename base::container_type::iterator    iterator;
    using            base::operator=;
    iterator        begin() { return base::c.begin(); }
    iterator        end() { return base::c.end() ; }
};


#endif // ** VMSTACK ** //
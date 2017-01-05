#include<iostream>
using namespace std;
 
//template<class T>
//class ScopedPtr
//{
//public:
//    ScopedPtr(T* ptr)
//        :_ptr(ptr)
//    {}
// 
//     ScopedPtr()
//        :_ptr(NULL)
//    {}
// 
//    ~ScopedPtr()
//    {
//        if (_ptr)
//        {
//            delete _ptr;
//            _ptr = NULL;
//        }
//    }
// 
//    T& operator*()
//    {
//        return *_ptr;
//    }
// 
//    T* GetPtr()
//    {
//        return _ptr;
//    }
// 
//protected:
//    ScopedPtr<T>(const ScopedPtr<T>& p);
//    ScopedPtr<T>& operator = (const ScopedPtr<T>& p);
// 
//private:
//    T* _ptr;
//};
// 
//void Test()
//{
//    ScopedPtr<int> p1(new int(2));
//    ScopedPtr<int> p2=p1;
//    ScopedPtr<int> p3(new int(3));
//    p3 = p1;
//}
// 
//int main()
//{
//    Test();
//    system("pause");
//    return 0;
//}

//#pragma once
//template<class T>
//class Sharedptr
//{
//public:
//    Sharedptr()
//        :_ptr(NULL)
//        , _pcount(new int(1))
//    {}
//    Sharedptr(T *ptr)
//        :_ptr(ptr)
//        , _pcount(new int(1))
//    {}
//    Sharedptr(const Sharedptr<T>& sp)
//        :_ptr(sp._ptr)
//        , _pcount(sp._pcount)
//    {
//        ++(*_pcount);
//    }
//    ~Sharedptr()
//    {
//        if (_ptr)
//        {
//            if (--(*_pcount)==0)
//            {
//                delete _ptr;
//                delete _pcount;
//                _ptr = NULL;
//                _pcount = NULL;
//            }
//            _ptr = NULL;
//        }
//    }
//    Sharedptr<T>& operator=(const Sharedptr<T> &sp)
//    {
//        if (this != &sp)
//        {
//            if (--(*_pcount) == 0)
//            {
//                delete _ptr;
//                delete _pcount;
//                _ptr = NULL;
//                _pcount = NULL;
//            }
//            _ptr = sp._ptr;
//            _pcount = sp._pcount;
//            ++(*_pcount);
//        }
//        return *this;
//    }
//private:
//    T* _ptr;
//    int *_pcount;
//};
//void test()
//{
//    int *a = new int(5);
//    Sharedptr<int> ap1(a);
//    Sharedptr<int> ap2(ap1);
//    Sharedptr<int> ap3;
//    ap3 = ap2;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}



template<class T>
class Autoptr
{
public:
    
    Autoptr(T *ptr)
        :_ptr(ptr)
    {}
	Autoptr()
        :_ptr(NULL)
    {}
    Autoptr<T>(Autoptr<T>& a)
        :_ptr(a._ptr)
    {
        a._ptr = NULL;
    }
    ~Autoptr()
    {
        if (_ptr)
        {
            delete _ptr;
            _ptr = NULL;
        }
    }
    Autoptr<T>& operator=(Autoptr<T>&a)
    {
        if (this != &a)
        {
            delete _ptr;
            _ptr = a._ptr;
            a._ptr = NULL;
        }
        return *this;
    }
    T& operator*()
    {
        return *_ptr;
    }
    T* Getptr()
    {
        return _ptr;
    }
 
protected:
    T *_ptr;
};
void test()
{
    Autoptr<int> ap0(new int(5));
	Autoptr<int> ap1(ap0);
	cout << *ap1 << endl;
    Autoptr<int> ap2(ap1);
    cout << *ap2 << endl;
    Autoptr<int> ap3;
    ap3 = ap2;
    cout << *ap3 << endl;
	
}

int main()
{
	test();
	system("pause");
	return 0;
}
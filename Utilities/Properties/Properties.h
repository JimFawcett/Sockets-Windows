#pragma once
/////////////////////////////////////////////////////////////////////
// Properties.h - provides getter and setter methods               //
// ver 1.0                                                         //
// Jim Fawcett, CSE687 - Object Oriented Design, Fall 2018         //
/////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
*  -------------------
*  This package provides a single Property<T> class that provides
*  getter and setter methods and backing store T t_ using the property 
*  name.
*  - Here's an example:
*      Property<int> intProp;
*      intProp(42)    Sets its internal store to 42
*      intProp()      returns the internal store value
*  - So one declaration creates two methods with simple syntax, using
*    the property's instance name. 
*  - The getter and setter methods are virtual, so you can override
*    them to provide logic that constraints getting and setting.
*
*  Required Files:
*  ---------------
*  Properties.h
*
*  Maintenance History:
*  --------------------
*  ver 1.0 : 11 Oct 2018
*  - first release
*/
namespace Utilities
{
  template <typename T>
  class Property
  {
  public:
    virtual ~Property() {}

    //----< setter assigns the state of t to the internal store >----

    virtual void operator()(const T& t)
    {
      t_ = t;
    }
    //----< getter returns the value of the internal store >---------
    /*
    *  - Return by value is used so that clients cannot change the
    *    internal store without using setter.
    */
    virtual T operator()()
    {
      return t_;
    }
    //---< return underlying type by reference >---------------------
    /*
    *  - Be careful using this, since clients can now bypass setter
    *    logic.
    */
    virtual T& ref()
    {
      return t_;
    }
  private:
    T t_;
  };
}

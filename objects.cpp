#include <iostream>
using namespace std;
// ---------------Obiectul de baza----------------------------
class Object
{
protected:
    virtual int CompareTo (Object const&) const = 0;
public:
    virtual ~Object ();
    virtual bool IsNull () const;
    virtual int Compare (Object const&) const;
    virtual void Put (ostream&) const = 0;
};

inline bool operator == (Object const& left, Object const& right)
    { return left.Compare (right) == 0; }

inline bool operator != (Object const& left, Object const& right)
    { return left.Compare (right) != 0; }

inline bool operator <= (Object const& left, Object const& right)
    { return left.Compare (right) <= 0; }

inline bool operator <  (Object const& left, Object const& right)
    { return left.Compare (right) <  0; }

inline bool operator >= (Object const& left, Object const& right)
    { return left.Compare (right) >= 0; }

inline bool operator >  (Object const& left, Object const& right)
    { return left.Compare (right) >  0; }

inline ostream& operator << (ostream& s, Object const& object)
    { object.Put (s); return s; }

// ---------------------Obiectul null----------------------

class NullObject : public Object
{
    static NullObject instance;

    NullObject ();
protected:
    int CompareTo (Object const&) const;
public:
    bool IsNull () const;
    void Put (ostream& s) const;

    static NullObject& Instance ();
};

NullObject NullObject::instance;

NullObject::NullObject ()
    {}

bool NullObject::IsNull () const
    { return true; }

int NullObject::CompareTo (Object const&) const
    { return 0; } 

void NullObject::Put (ostream& s) const
    { s << "NullObject"; }

NullObject& NullObject::Instance ()
    { return instance; }

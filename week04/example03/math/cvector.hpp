class CVector {
public:
    int x,y;
    CVector () {}
    CVector (int a, int b) : x(a), y(b) {}
    CVector operator+(const CVector& rhs);
};


#ifndef BITSET_H
#define BITSET_H
#include <string>
#include <cmath>
#include <algorithm>


class BITSET
{
    unsigned long long value;

public:


    BITSET() {
        value = 0;
    }


    void set(int pos)
    {
        unsigned long long i = 1;
        value |= (i << pos);
    }


    int count()
    {
        int result = 0;
        int s = sizeof(value);
        for (int i = 0; i < sizeof(value) * 8; i++)
        {
            if (test(i))
                result++;
        }
        return result;
    }


    void reset(int pos)
    {
        unsigned long long i = 1;
        value &= ~(i << pos);
    }


    bool test(int pos)
    {
        unsigned long long i = 1;
        return value & (i << pos);
    }


    bool any()
    {
        return count() > 0;
    }


    bool none()
    {
        return count() == 0;
    }


    unsigned long long ReturnValue()
    {
        return value;
    }


    bool all()
    {
        return sizeof(value) * 8 == count();
    }


    std::string toString()
    {
        std::string result;
        int s = sizeof(value);
        for (int i = 63; i >= 0; i--)
        {
            if (test(i))
            {
                result.push_back('1');
            }
            else
            {
                result.push_back('0');
            }
        }

        //std::reverse(result.begin(), result.end());
        return result;
    }


    int size()
    {
        return sizeof(value) * 8;
    }


    void flip()
    {
        value = ~value;
    }


    unsigned long to_ullong()
    {
        std::string str = toString();
        unsigned long res = 0;
        for (int i = 0; i < str.length(); i++)
        {
            int tmp = pow(2, 63 - i);
            if (str[i] == '1')
            {
                res += tmp;
            }
        }
        return res;
    }


    unsigned long long to_ulong()
    {
        std::string str = toString();
        unsigned long long res = 0;
        for (int i = 0; i < sizeof(value) * 8; i++)
        {
            if (str[i] == '0')
                res += 0;
            else
                res += pow(2, 63 - i);
        }
        return res;
    }


    BITSET& operator&=(const BITSET& b)
    {
        value &= b.value;
        return *this;
    }


    BITSET& operator|=(const BITSET& b)
    {
        value |= b.value;
        return *this;
    }


    BITSET& operator^=(const BITSET& b)
    {
        value ^= b.value;
        return *this;
    }


    BITSET& operator=(const BITSET& b)
    {
        value = b.value;
        return *this;
    }


    BITSET& operator<<=(int pos)
    {
        value <<= pos;
        return *this;
    }


    BITSET& operator>>=(int pos)
    {
        value >>= pos;
        return *this;
    }


    BITSET operator~()
    {
        BITSET temp;
        temp.value = ~value;
        return temp;
    }


    BITSET operator&(const BITSET& b) const
    {
        BITSET temp;
        temp = *this;
        temp &= b;
        return temp;
    }


    BITSET operator|(const BITSET& b) const
    {
        BITSET temp;
        temp = *this;
        temp |= b;
        return temp;
    }


    BITSET operator^(const BITSET& b) const
    {
        BITSET temp;
        temp = *this;
        temp ^= b;
        return temp;
    }


    BITSET operator<<(int pos) const
    {
        BITSET temp;
        temp = *this;
        temp <<= pos;
        return temp;
    }


    BITSET operator>>(int pos) const
    {
        BITSET temp;
        temp = *this;
        temp >>= pos;
        return temp;
    }


    bool operator==(const BITSET& b) const
    {
        return value == b.value;
    }

    bool operator!=(const BITSET& b) const
    {
        return value != b.value;
    }


    bool operator[](int pos)
    {
        if (test(pos))
            return true;
        return false;
    }
};

#endif // BITSET_H

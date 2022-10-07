

class MyEnum
{
    enum class Value : char
    {
        VALUE1 = '1',
        VALUE2 = '2'
    };

    const char* to_string(Value value)
    {
        switch (value)
        {
        case Value::VALUE1:
            return "1";
        case Value::VALUE2:
            return "2";
        default:
            return "Invalid";
        }
    }
};
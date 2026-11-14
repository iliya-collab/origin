template <typename Ex, typename Fn>
void ExpectExactThrow(Fn&& f, const char* expectedMsg = nullptr)
{
    try
    {
        f();
        ADD_FAILURE() << "No exception was thrown";
    }
    catch(const std::exception& e)
    {
        EXPECT_EQ(typeid(e), typeid(Ex)) << "Thrown: " << typeid(e).name;
        if (expectedMsg)
            EXPECT_STREQ(e.what(), expectedMsg);
    }
    catch (...)
    {
        ADD_FAILURE() << "An exception other than std::exception was thrown";
    }
    
}
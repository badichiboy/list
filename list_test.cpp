
#include "list.h"
#include "utils.h"

typedef int T;

bool getsize()
{
    list<T> new_list;
    ASSERT_TEST(new_list.getSize()==0);
    new_list.addToEnd(5);
    ASSERT_TEST(new_list.getSize()==1);
    new_list.addToStart(6);
    ASSERT_TEST(new_list.getSize()==2);
    new_list.addNode(1,7);
    ASSERT_TEST(new_list.getSize()==3);
    new_list.deleteNode(2);
    ASSERT_TEST(new_list.getSize()==2);
    new_list.deleteEnd();
    ASSERT_TEST(new_list.getSize()==1);
    new_list.deleteStart();
    ASSERT_TEST(new_list.getSize()==0);
    return true;
}

bool addToEnd()
{
    list<T> new_list;
    new_list.addToEnd(0);
    ASSERT_TEST(new_list.getData(1)==0);
    ASSERT_TEST(new_list.getSize()==1);

    for (int i=0;i<12;i++)
    {
        new_list.addToEnd(i+1);
    }

    ASSERT_TEST(new_list.getSize()==13);
    for (int i=0;i<13;i++)
    {
        ASSERT_TEST(new_list.getData(i+1)==i);
    }
    return true;
}

bool addToStart()
{
    list<T> new_list;
    new_list.addToStart(0);
    ASSERT_TEST(new_list.getData(1)==0);
    ASSERT_TEST(new_list.getSize()==1);

        for (int i=0;i<12;i++)
    {
        new_list.addToStart(i+1);
    }

    ASSERT_TEST(new_list.getSize()==13);
    for (int i=13;i>0;i--)
    {
        ASSERT_TEST(new_list.getData(14-i)==i-1);
    }
    return true;

}

bool addNode()
{
    list<T> new_list;
    for(int i=0;i<10;i++)
    {
        new_list.addToEnd(i);
    }
    new_list.addNode(5,12);
    ASSERT_TEST(new_list.getData(6)==12);
    ASSERT_TEST(new_list.getSize()==11);
    ASSERT_ERROR(new_list.addNode(32,5),OutOfRange);
    return true;
}
bool deleteEnd()
{
    list<T> new_list;
    for(int i=0;i<10;i++)
    {
        new_list.addToEnd(i);
    }
    new_list.deleteEnd();
    ASSERT_TEST(new_list.getSize()==9);
    ASSERT_TEST(new_list.getData(9)==8);
    list<T> new_list2;
    ASSERT_ERROR(new_list2.deleteEnd(),EmptyList);
    return true;
}
bool deleteStart()
{
    list<T> new_list;
    for(int i=0;i<10;i++)
    {
        new_list.addToEnd(i);
    }
    new_list.deleteStart();
    ASSERT_TEST(new_list.getSize()==9);
    ASSERT_TEST(new_list.getData(9)==9);
    list<T> new_list2;
    ASSERT_ERROR(new_list2.deleteStart(),EmptyList);
    return true;
}

bool DeleteNode()
{
    list<T> new_list;
    for(int i=0;i<10;i++)
    {
        new_list.addToEnd(i);
    }
    ASSERT_TEST(new_list.getData(5)==4);
    new_list.deleteNode(5);
    ASSERT_TEST(new_list.getSize()==9);
    ASSERT_TEST(new_list.getData(5)==5);
    list<T> new_list2;
    ASSERT_ERROR(new_list2.deleteNode(5),EmptyList);
    return true;
}

bool findfunction()
{
     list<T> new_list;
    for(int i=0;i<10;i++)
    {
        new_list.addToEnd(i);
    }
    ASSERT_TEST(new_list.find(5)==6);
    ASSERT_TEST(new_list.find(555)==-1);
    list<T> new_list2;
    ASSERT_TEST(new_list.find(123)==-1);
    return true;
}
int main()
{
    std::map<std::string, std::function<bool()>> tests;


    ADD_TEST(getsize);
    ADD_TEST(addToEnd);
    ADD_TEST(addToStart);
    ADD_TEST(addNode);
    ADD_TEST(deleteEnd);
    ADD_TEST(deleteStart);
    ADD_TEST(DeleteNode);
    ADD_TEST(findfunction)

    int passed = 0;
    for (std::pair<std::string, std::function<bool()>> element : tests)
    {
        passed += run_test(element.second, "Running " + element.first);
    }

    cout<<"Passed "<<passed<<" out of "<<tests.size()<<" tests."<<endl;

    return 0;
}
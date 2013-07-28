#include "Hash_table.h"

int main ()
{
    bool success = false;
    hashTable<std::string> hTable(20);
    success = hTable.insertElem("hello");
    success = hTable.insertElem("fish");
    success = hTable.insertElem("apple");
    success = hTable.insertElem("cat");
    success = hTable.findElem("hello");
    hTable.displayTable();
    success = hTable.deleteElem("hello");
    success = hTable.deleteElem("fish");
    success = hTable.deleteElem("apple");
    success = hTable.findElem("hello");
    hTable.displayTable();
    return 0;
}
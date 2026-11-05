// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    struct Student { uint roll; string name; uint marks; }
    Student[] public students;

    function add(uint roll, string memory name, uint marks) public { students.push(Student(roll, name, marks)); }

    function get(uint i) public view returns (uint, string memory, uint) {
        Student memory s = students[i];
        return (s.roll, s.name, s.marks);
    }

    function count() public view returns (uint) { return students.length; }

    fallback() external payable {}
    receive() external payable {}
}
// Deploy in Remix -> call add(); check "transaction cost" / "execution cost" (gas) in the console log.

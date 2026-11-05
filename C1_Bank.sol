// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank {
    mapping(address => uint) bal;

    function deposit() public payable { bal[msg.sender] += msg.value; }

    function withdraw(uint amt) public {
        require(bal[msg.sender] >= amt, "Insufficient balance");
        bal[msg.sender] -= amt;
        payable(msg.sender).transfer(amt);
    }

    function getBalance() public view returns (uint) { return bal[msg.sender]; }
}

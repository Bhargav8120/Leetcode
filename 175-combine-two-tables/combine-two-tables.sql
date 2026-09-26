/* Write your PL/SQL query statement below */

select firstName , lastName , city , state
from Person left join Address
on Person.personID = Address.personId
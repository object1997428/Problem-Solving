select
case when SKILL_CODE & (select sum(code) from SKILLCODES where CATEGORY = "Front End") and SKILL_CODE & (select code from SKILLCODES where NAME = "Python") then 'A'
when SKILL_CODE & (select code from SKILLCODES where NAME = "C#") then 'B'
when SKILL_CODE & (select sum(code) from SKILLCODES where CATEGORY = "Front End") then 'C'
else null end as `GRADE`,
ID, EMAIL
from DEVELOPERS
having `GRADE` is not null
order by `GRADE`, ID;
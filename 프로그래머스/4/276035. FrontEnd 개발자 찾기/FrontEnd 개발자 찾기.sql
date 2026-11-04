



select ID, EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS
where SKILL_CODE&(
    select sum(CODE)
    from SKILLCODES A
    where CATEGORY = 'Front End'
) > 0
order by ID;
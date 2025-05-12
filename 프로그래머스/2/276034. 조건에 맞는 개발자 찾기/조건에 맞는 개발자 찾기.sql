select distinct(ID), EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS, (
    select CODE
    from SKILLCODES
    where NAME = 'Python' or NAME = 'C#'
) as c
where SKILL_CODE&(CODE)
order by ID;
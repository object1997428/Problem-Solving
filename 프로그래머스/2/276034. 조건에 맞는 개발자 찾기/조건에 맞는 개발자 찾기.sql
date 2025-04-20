select distinct(a.ID), EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS a
,(
    select CODE
    from SKILLCODES
    where NAME='Python' or NAME='C#'
) b
where (a.SKILL_CODE&b.CODE)
order by ID;
select distinct(ID), EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS a,
(
    select CODE
    from SKILLCODES
    where NAME='C#' or NAME='Python'
) as b
where (a.SKILL_CODE&b.CODE)
order by ID
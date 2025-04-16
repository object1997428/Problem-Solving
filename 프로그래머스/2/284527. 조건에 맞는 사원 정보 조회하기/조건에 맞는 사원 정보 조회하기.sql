

select mSCORE as SCORE, a.EMP_NO, EMP_NAME, POSITION, EMAIL
from HR_EMPLOYEES a
join (
    select aa.EMP_NO, mSCORE
    from (
        select EMP_NO, sum(SCORE) as sSCORE
        from HR_GRADE
        where YEAR = 2022
        group by EMP_NO
    ) as aa,
    (
        select max(sSCORE) as mSCORE
        from (
            select EMP_NO, sum(SCORE) as sSCORE
            from HR_GRADE
            where YEAR = 2022
            group by EMP_NO
        ) as b
    ) as bb
    where aa.sSCORE=bb.mSCORE
) cc on cc.EMP_NO=a.EMP_NO





# select EMP_NO, sum(SCORE) as sSCORE
# from HR_GRADE
# where YEAR
# group by EMP_NO
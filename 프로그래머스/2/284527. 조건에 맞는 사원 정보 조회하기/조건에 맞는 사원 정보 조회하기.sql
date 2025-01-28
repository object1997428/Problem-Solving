select `sums` SCORE, a.EMP_NO, a.EMP_NAME, a.POSITION, a.EMAIL
from HR_EMPLOYEES a
join(
    select sum(SCORE) as `sums`, EMP_NO
    from HR_GRADE b
    where year='2022'
    group by EMP_NO
    order by `sums` desc
    limit 1
) as b on a.EMP_NO=b.EMP_NO;
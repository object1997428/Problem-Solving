-- 코드를 작성해주세요
select count(ID) as COUNT
from ECOLI_DATA
where (((GENOTYPE%2)=1)or(floor(GENOTYPE/4)%2=1)) and (floor(GENOTYPE/2)%2!=1);
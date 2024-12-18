select a.ID, a.GENOTYPE, b.GENOTYPE as PARENT_GENOTYPE
from ECOLI_DATA a
left join (
    select e.ID, e.GENOTYPE
    from ECOLI_DATA e
) b on a.PARENT_ID=b.ID
where a.GENOTYPE&b.GENOTYPE=b.GENOTYPE
order by a.ID;
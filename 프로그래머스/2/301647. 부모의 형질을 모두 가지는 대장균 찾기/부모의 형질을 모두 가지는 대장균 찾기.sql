SELECT a.ID, a.GENOTYPE, b.GENOTYPE as PARENT_GENOTYPE
FROM ecoli_data a
left join (
    select id, PARENT_ID, GENOTYPE
    from ECOLI_DATA
) as b
on a.PARENT_ID=b.ID
where ((a.GENOTYPE&b.GENOTYPE)&b.GENOTYPE)=b.GENOTYPE
order by a.ID asc;
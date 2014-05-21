function table_concat(first_table, second_table)
	for k, v in pairs(second_table) do
			first_table[k] = v
	end
	
	return first_table
end

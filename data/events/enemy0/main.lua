enemy0 = EnemyEvent.new("enemy0", 0)

enemy0.init = function()
	enemy0 = enemy0:initCharacter();
	
	enemy0.movements = {
		function() enemy0.character:moveLeft() end,
		function() enemy0.character:moveUp() end,
		function() enemy0.character:moveRight() end,
		function() enemy0.character:moveDown() end
	}
end


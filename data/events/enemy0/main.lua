enemy0 = LuaEvent.new("enemy0")

enemy0.init = function()
	enemy0 = enemy0:initEvent()

	enemy0.event:setHitbox(8, 8, 64, 64)
	enemy0.event:setPosition(enemy0.event:x() - 8, enemy0.event:y() - 8)

	enemy0.update = function()
		if CharacterManager.getInstance():player():inFrontOf(enemy0.event)
		and Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
			enemy0.event:face(CharacterManager.getInstance():player())

			enemy0:addAction(0, LuaEvent.startBattle, 0, false, -1, -1, -1);
		end
	end

	enemy0.movements = {
		function() enemy0.event:moveLeft() end,
		function() enemy0.event:moveUp() end,
		function() enemy0.event:moveRight() end,
		function() enemy0.event:moveDown() end
	}
end


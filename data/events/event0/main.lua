event0 = LuaEvent.new("event0")

event0.init = function()
	event0 = event0:initEvent()

	event0.update = function()
		if CharacterManager.getInstance():player():inFrontOf(event0.event)
		and Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
			event0.event:face(CharacterManager.getInstance():player())

			event0:addAction(0, LuaEvent.drawText, _t("event0-0"), 1)
			event0:addAction(1, LuaEvent.drawText, _t("event0-1"), -1)
		end
	end

	event0.movements = {
		function() event0.event:moveLeft() end,
		function() event0.event:moveUp() end,
		function() event0.event:moveRight() end,
		function() event0.event:moveDown() end
	}
end


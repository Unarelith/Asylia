event0 = {}

event0.init = function()
	event0.character = MapManager.currentMap:getEvent("event0")
	
	event0.update = function()
		
	end
	
	event0.render = function()
		
	end
	
	event0.action = function()
		if Keyboard.isKeyPressedWithDelay(Keyboard.GameAttack, 5000) then
			ActivityManager.newDialog();
		end
	end
	
	event0.collisionAction = function()
		
	end
end


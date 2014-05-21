dofile("data/lualibs/Utilities.lua")

CharacterEvent = {}

CharacterEvent.new = function(eventName, nbOfMessages)
	local initCharacter = function(self)
		local character = MapManager.currentMap:getEvent(eventName)
		
		local update = function() end
		
		local render = function()
			character:render()
		end
		
		local action = function()
			if Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
				character:setDirection(3 - CharacterManager.player():getDirection())
				
				local dialog = ActivityManager.newDialog()
				
				for i = 0, nbOfMessages - 1 do
					dialog:addMessage(_t(eventName .. "-" .. tostring(i)))
				end
			end
		end
		
		local collisionAction = function() end
		
		return character, table_concat(self, {
			update = update,
			render = render,
			action = action,
			collisionAction = collisionAction,
		})
	end
	
	return {
		initCharacter = initCharacter,
		
		eventName = eventName,
		nbOfMessages = nbOfMessages
	}
end


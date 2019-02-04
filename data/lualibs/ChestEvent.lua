ChestEvent = {}

ChestEvent.new = function(eventName, itemID, itemCount)
	local initChest = function(self)
		self.character = MapManager.currentMap():getEvent(eventName)
		self.opened = false
		self.chestType = 1
		self.animationAtEnd = false
		self.empty = false

		self.itemID = itemID
		self.itemCount = itemCount

		self.update = function()
			if Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
				if CharacterManager.player():getDirection() == 3 and not self.opened then
					self.opened = true
				end
			end

			if self.animationAtEnd and not self.empty then
				local item = ItemManager.getItem(self.itemID)

				StateManager.drawMessage(_t("Obtained") .. " " .. self.itemCount .. " " .. item:name())

				CharacterManager.player():inventory():addItem(self.itemID, self.itemCount, 1)

				self.empty = true
			end
		end

		self.render = function()
			if self.opened then
				if not self.character:animationAtEnd(self.chestType) then
					self.character:playAnimation(self.character:x() - Map.scrollX(), self.character:y() - Map.scrollY(), self.chestType)
				else
					self.animationAtEnd = true
					self.character:drawFrame(self.character:x() - Map.scrollX(), self.character:y() - Map.scrollY(), self.chestType + 3 * 4)
				end
			else
				self.character:drawFrame(self.character:x() - Map.scrollX(), self.character:y() - Map.scrollY(), self.chestType)
			end
		end

		self.movements = {
			function() end
		}

		return self
	end

	return {initChest = initChest}
end

#pragma once

/*#include "mcpe/entity/Mob.h"
#include "mcpe/gamemode/GameType.h"
#include "mcpe/util/FullBlock.h"*/
#include "../Mob.h"
#include "../../gamemode/GameType.h"

class ChunkSource;
class GlobalPermissionsLevel;
class UserPermissionsLevel;
class PlayerListener;
class BlockEntity;
class TelemetryEventPacket;
class Inventory;
class Tick;
class SkinInfoData;
class CooldownType;
class Agent;
class IContainerManager;
class NetworkIdentifier;
class PacketSender;
class EventPacket;
class ChalkboardBlockEntity;
class CommandPermissionLevel;
class Agent;

class Player : public Mob 
{
public:
	char filler2[2971];
	bool creativeMode;
	bool surivivalMode;
public:
	virtual ~Player();
	virtual void reloadHardcoded(Entity::InitializationMethod, VariantParameterList const&);
	virtual void initializeComponents(Entity::InitializationMethod, VariantParameterList const&);
	virtual void remove();
	virtual void teleportTo(Vec3 const&, int, int);
	virtual void getAddPacket();
	virtual void normalTick();
	virtual void rideTick();
	virtual int getRidingHeight();
	virtual std::string getFormattedNameTag() const;
	virtual int getHeadHeight() const;
	virtual int getCameraOffset() const;
	virtual bool isImmobile() const;
	virtual bool isPushable() const;
	virtual bool isPushableByPiston() const;
	virtual bool isShootable();
	virtual bool isCreativeModeAllowed();
	virtual bool isInvulnerableTo(EntityDamageSource const&) const;
	virtual void onBounceStarted(BlockPos const&, FullBlock const&);
	virtual void feed(int);
	virtual void handleEntityEvent(EntityEvent, int);
	virtual void awardKillScore(Entity&, int);
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, ItemInstance const&);
	virtual EntityType getEntityTypeId() const;
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual void onSynchedDataUpdate(int);
	virtual bool canBePulledIntoVehicle() const;
	virtual void sendMotionPacketIfNeeded();
	virtual bool useItem(ItemInstance&) const;
	virtual void getMapDecorationRotation();
	virtual bool isWorldBuilder();
	virtual bool isCreative() const;
	virtual void isAdventure() const;
	virtual void add(ItemInstance&);
	virtual void _hurt(EntityDamageSource const&, int, bool, bool);
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(CompoundTag const&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void die(EntityDamageSource const&);
	virtual bool isSleeping() const;
	virtual float getSpeed() const;
	virtual void setSpeed(float);
	virtual void actuallyHurt(int, EntityDamageSource const*, bool);
	virtual void travel(float, float);
	virtual void aiStep();
	virtual ItemInstance* getCarriedItem();
	virtual UseDuration getItemUseDuration();
	virtual float getItemUseStartupProgress();
	virtual float getItemUseIntervalProgress();
	virtual void getAllHand() const;
	virtual void getAllEquipment() const;
	virtual void sendInventory() const;
	virtual void jumpFromGround();
	virtual void updateAi();
	virtual void getExperienceReward() const;
	virtual void dropEquipment(EntityDamageSource const&, int);
	virtual void useNewAi() const;
	virtual void prepareRegion(ChunkSource&);
	virtual void destroyRegion();
	virtual void suspendRegion();
	virtual void onPrepChangeDimension();
	virtual void onDimensionChanged();
	virtual void changeDimensionWithCredits(DimensionId);
	virtual void tickWorld(Tick const&);
	virtual void moveView();
	virtual void setName(std::string const&);
	virtual void checkMovementStats(Vec3 const&);
	virtual void getCurrentStructureFeature() const;
	virtual void respawn();
	virtual void resetPos(bool);
	virtual bool isInTrialMode();
	virtual void hasResource(int);
	virtual void completeUsingItem();
	virtual void setPermissions(CommandPermissionLevel);
	virtual void startCrafting(BlockPos const&, bool);
	virtual void startStonecutting(BlockPos const&);
	virtual void startDestroying();
	virtual void stopDestroying();
	virtual void openContainer(int, BlockPos const&);
	virtual void openContainer(int, EntityUniqueID const&);
	virtual void openFurnace(int, BlockPos const&);
	virtual void openEnchanter(int, BlockPos const&);
	virtual void openAnvil(int, BlockPos const&);
	virtual void openBrewingStand(int, BlockPos const&);
	virtual void openHopper(int, BlockPos const&);
	virtual void openHopper(int, EntityUniqueID const&);
	virtual void openDispenser(int, BlockPos const&, bool);
	virtual void openBeacon(int, BlockPos const&);
	virtual void openPortfolio();
	virtual void openCommandBlock(BlockPos const&);
	virtual void openCommandBlockMinecart(EntityUniqueID const&);
	virtual void openHorseInventory(int, EntityUniqueID const&);
	virtual void openTrading(EntityUniqueID const&);
	virtual bool canOpenContainerScreen();
	virtual void openChalkboard(ChalkboardBlockEntity&);
	virtual void openNpcInteractScreen(Entity&);
	virtual void openInventory();
	virtual void openStructureEditor(BlockPos const&);
	virtual void displayChatMessage(std::string const&, std::string const&);
	virtual void displayClientMessage(std::string const&);
	virtual void displayLocalizableMessage(std::string const&, std::vector<std::string, std::allocator<std::string> > const&, bool);
	virtual void displayWhisperMessage(std::string const&, std::string const&);
	virtual void startSleepInBed(BlockPos const&);
	virtual void stopSleepInBed(bool, bool);
	virtual bool canStartSleepInBed();
	virtual void getSleepTimer() const;
	virtual void openSign(BlockPos const&);
	virtual bool isLocalPlayer() const;
	virtual void stopLoading();
	virtual void registerTrackedBoss(EntityUniqueID);
	virtual void unRegisterTrackedBoss(EntityUniqueID);
	virtual void setPlayerGameType(GameType);
	virtual void _crit(Entity&);
	virtual void getEventing() const;
	virtual void sendEventPacket(EventPacket const&) const;
	virtual void addExperience(int);
	virtual void addLevels(int);
	virtual void setContainerData(IContainerManager&, int, int)=0;
	virtual void slotChanged(IContainerManager&, int, ItemInstance const&, ItemInstance const&, bool)=0;
	virtual void refreshContainer(IContainerManager&, std::vector<ItemInstance, std::allocator<ItemInstance> > const&)=0;
	virtual void deleteContainerManager();
	virtual void setFieldOfViewModifier(float);
	virtual bool isPositionRelevant(DimensionId, BlockPos const&);
	virtual bool isEntityRelevant(Entity const&);
	virtual bool isTeacher() const=0;
	virtual void onSuspension();
	virtual void startCooldown(Item*);
	virtual void getItemCooldownLeft(CooldownType) const;
	virtual bool isItemInCooldown(CooldownType) const;
	virtual void onMovePlayerPacketNormal(Vec3 const&, Vec2 const&);
public:
	enum class PositionMode:int
	{
		
	};
public:
	Player(Level&, PacketSender&, GameType, NetworkIdentifier const&, std::unique_ptr<SkinInfoData, std::default_delete<SkinInfoData> >, mce::UUID);
	void crackBlock(BlockPos const&, signed char);
	void getSupplies() const;
	void getTrackedBosses();
	void setSkin(std::string const&, std::vector<unsigned char, std::allocator<unsigned char> > const&);
	bool isInCreativeMode();
	void setContainerManager(std::shared_ptr<IContainerManager>);
	bool isChatAllowed();
	void getHudContainerManagerModel();
	void getPermissions() const;
	int getPlayerLevel() const;
	float getLevelProgress() const;
	ItemInstance* getSelectedItem() const;
	void setChunkRadius(int);
	void setSelectedItem(ItemInstance const&);
	void getContainerManager();
	void setAllPlayersSleeping();
	void setTeleportDestination(Vec3 const&);
	void setRespawnPosition(BlockPos const&, bool);
	void handleMovePlayerPacket(Player::PositionMode, Vec3 const&, Vec2 const&, float);
	void getSkin() const;
	void stopGliding();
	void startGliding();
	void stopUsingItem();
	void getSpawnPosition();
	void getTicksUsingItem();
	void recheckSpawnPosition();
	bool isUsingItem() const;
	ItemInstance* getItemInUse() const;
	int getChunkRadius() const;
	void startUsingItem(ItemInstance const&, int);
	void getCapePos(float);
	void getSleepRotation();
	void addListener(PlayerListener&);
	void removeListener(PlayerListener&);
	void canUseCarriedItemWhileMoving();
	bool isBouncing() const;
	bool isHiddenFrom(Mob&) const;
	void handleJumpEffects();
	void updateTeleportDestPos();
	bool canDestroy(Block const&) const;
	bool isSurvival() const;
	void getClientId() const;
	void getCertificate() const;
	bool isForcedRespawn() const;
	void sendInventorySlot(int) const;
	void isSleepingLongEnough() const;
	void getNewEnchantmentSeed();
	void getEnchantmentSeed() const;
	void canUseCommandBlocks() const;
	void spawnExperienceOrb(Vec3 const&, int);
	void take(Entity&, int);
	void getLuck();
	void _addLevels(int);
	void getMapIndex();
	void setMapIndex(int);
	void setBedOffset(int);
	void _tickCooldowns();
	void setPlayerIndex(int);
	void getAttackDamage();
	void _applyExhaustion(Vec3 const&);
	void releaseUsingItem();
	void resetPlayerLevel();
	void registerAttributes();
	void causeFoodExhaustion(float);
	void updateTrackedBosses();
	void setDefaultHeadHeight();
	void setRespawnDimensionId(DimensionId);
	void _getAdjustedViewRadius();
	void _ensureSafeSpawnPosition(Vec3&);
	void _registerElytraLoopSound();
	void shouldUpdateBossGUIBinds();
	void fireDimensionChangedEvent(DimensionId);
	void getStandingPositionOnBlock(BlockPos const&);
	void shouldUpdateBosGUIControls();
	void eat(ItemInstance const&);
	void eat(int, float);
	void _touch(Entity&);
	void attack(Entity&);
	bool isHurt();
	void checkBed(bool);
	void getScore();
	void interact(Entity&);
	void moveCape();
	void setAgent(Agent*);
	void getDirection() const;
	void getPlayerIndex() const;
	void getDestroySpeed(Block const&) const;
	void fixSpawnPosition(BlockPos&, std::vector<BlockSource*, std::allocator<BlockSource*> >) const;
	void hasOpenContainer() const;
	void getDestroyProgress(Block const&) const;
	void hasRespawnPosition() const;
	void _getItemDestroySpeed(Block const&) const;
	void fixStartSpawnPosition(BlockPos&, std::vector<BlockSource*, std::allocator<BlockSource*> >) const;
	void getXpNeededForNextLevel() const;
	Agent* getAgent() const;
	bool isHungry() const;
	bool isViewer() const;
public:
	static float const DISTANCE_TO_TRANSFORM_EVENT;
	static float const DISTANCE_TO_TRAVELLED_EVENT;
	static float const HUNGER;
	static float const DEFAULT_PLAYER_HEIGHT_OFFSET;
	static float const SATURATION;
	static float const EXHAUSTION;
	static float const EXPERIENCE;
	static float const DEFAULT_BB_WIDTH;
	static float const DEFAULT_BB_HEIGHT;
	static float const DEFAULT_FLY_SPEED;
	static float const DEFAULT_WALK_SPEED;
	static float const PLAYER_GLIDING_CAMERA_OFFSET;
	static float const LEVEL;
};

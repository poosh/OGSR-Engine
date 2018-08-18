#pragma once
// Для изменения настроек нужно создать папку build_config_overrides,
// скопировать этот файл в нее и изменить, как требуется.

//****************************************************************************************************
// Сборка в режиме совместимости с вальнильным ТЧ. Выключает специфичные для ОГСЕ правки.
//#define SHOC_EDITION

//Хак, чтобы AppVeyor собирал именно SHOC_EDITION
#if __has_include("hack.appveyor")
#	pragma message("[AppVeyor] Enabled SHOC_EDITION mode!")
#	define SHOC_EDITION
#endif
//****************************************************************************************************

// Если функция в precondition диалога не найдена, будем падать, вместо того,
// что бы просто выводить сообщение в лог и игнорировать этот precondition.
//#define CRASH_ON_PRECONDITION_NOT_FOUND


// Убирает возможность назначать альтернативные кнопки. Т.е. убирает второй
// столбец в настройках и отключает консольную команду bind_sec.
#define REMOVE_ALTERNATIVE_KEYBOARD_BINDING

// Включает использование шейдерного кэша
//#define USE_SHADER_CACHE

// Другая реализация равнозначных слотов, из xp-dev. Позволяет задавать список
// допустимых слотов в параметре "slot". Вот так:
//   slot = 2,3
#ifdef SHOC_EDITION
#	define NEW_WPN_SLOTS
#endif

// Показывать расширенное контекстное меню для равнознычных слотов.
// Добовляет пункты переместить в каждый доступный слот
// Для адднов добовляет пункты установить на каждое доступное оружие
//#define NEW_WPN_SLOTS_EXTEND_MENU

// Оружие на классе бинокля будет вести себя, как оружие,
// т.е. стрелять, показывать кол-во патронов на худе и т.п. Бинокль
// тоже будет показывать на худе кол-во патронов, 0 патронов. В
// качестве альтернативы, нужному оружию можно добавить один из
// следующих параметров или оба, в зависимости от желаемого результат:
//
// scope_dynamic_zoom = true
// vision_present     = true
//
// и при прицеливании оно будет обладать свойствами бинокля. Еще нужно
// не забыть добавить в секцию этого оружия настройки для бинокля.
#define BINOC_FIRING

// Отключает возможность переключаться между слотами колесиком мыши.
// http://www.amk-team.ru/forum/topic/13383-soc-melkie-pravki-dvizhka/?do=findComment&comment=1124304
#define NO_MOUSE_WHEEL_SWITCH_SLOT

// Заблокировать авто-перезарядку и сброс зума, когда закончились
// патроны.
#define NO_AUTO_RELOAD_WPN

// включает хранилище скриптовых переменных в сейвы
#define SCRIPT_VARS_STORAGE

// включает экспорт функции setup_game_icon в Lua
#define SCRIPT_ICONS_CONTROL

// Выключает использование анимации рассматривания болта, подкидывания гранат
// и кручения ножа, т.е. anim_playing.
#define STOP_ANIM_PLAYING

// При проблемах в скриптовых биндерах будем падать, а не просто
// ругаться в лог.
#define CRASH_ON_SCRIPT_BINDER_ERRORS

// Включает коллизию с трупами. Это значит, что мобы будут тупить,
// уперевшись в тушку мутантами, т.к. не умеют обходить препятствия.
#define CORPSES_COLLISION

// Скрывать оружие при открытом диалоге, инвентаре и т.п.
//#define MORE_HIDE_WEAPON

// Включает альтернативную реализацию загрузки скриптов из подкаталогов scripts ( из CoC ).
// KRodin: По умолчанию используется реализация из xp-dev, т.к. реализация из CoC лично у меня глючит.
//#define LOAD_SCRIPTS_SUBDIRS

// включает экспорт класса CEffectorZoomInertion для управления движением
// прицела
#define SCRIPT_EZI_CONTROL

// Вычисление и использование правильного положения солнца, вместо позиции из
// погодных конфигов.
#define DYNAMIC_SUN_MOVEMENT

// Выключить музыкальный эмбиент по умолчанию. Можно включить командой
// "g_music_tracks on".
#define G_MUSIC_TRACKS_OFF

// Добавляет небольшую задержку между рендерингом кадров, чтобы зря не
// насиловать видеокарту при больших FPS.
//#define ECO_RENDER

// Запрещает заряжать в дробовики патроны разного типа
#define SHOTG_EXTRA_AMMO_FIX

// Red Virus: bobbing effect from lost alpha
//#define WPN_BOBBING

// Очистка списка задач при загрузке сейва от выполненных и проваленных
//#define KEEP_INPROGRESS_TASKS_ONLY

// Сколько последних сообщений показывать в истории ПДА
#define NEWS_TO_SHOW 500

// Показывать полоску состояния предметов в инвентаре, на его
// иконке. Включает поддержку аттрибута condition_progress_bar для
// dragdrop элементов и статиков condition_progess_bar и
// cell_item_text.
//#define SHOW_INV_ITEM_CONDITION

// Показывать порядковый номер перед фразами в диалогах. Для этой
// опции необходимо изменить talk.xml и добавить туда статик
// "num_text" в "question_item", как это сделано в ЗП. Порядковые
// номера соответствуют акселлераторам, назначенным этим фразам. Этот
// дефайн нужен только для отображения номеров. Акселлераторы работают
// без этого дефайна.
//#define SHOW_DIALOG_NUMBERS

// Трупы будут игнорировать коллизии со всеми динамическими
// объектами. Насколько я понимаю, по умолчанию трупы игноруруют
// коллизии только с живыми мобами. С этим дефайном гора трупов не
// будет лагать.
//#define CORPSES_IGNORE_DYNAMIC

// эффект Доплера для звука из xp-dev
//#define SND_DOPPLER_EFFECT

// Радиоактивные предметы в инвентаре будут увеличивать радиацию. Тоже самое
// касается предметов, которые ухудшают пси-здоровье, если определен
// AF_PSY_HEALTH.
//#define OBJECTS_RADIOACTIVE

// Артефакты с нулевым состоянием работать не будут.
#define AF_ZERO_CONDITION

// Влияение артефактов на сытость будет работать.
#define AF_SATIETY

// У артефактов будет свойство восстановления пси-здоровья.
#define AF_PSY_HEALTH

// Обрабатывать свойства артефактов для брони. Имеются ввиду всякие
// _restore_speed.
#define OUTFIT_AF

// Включает увеличение параметра snd_targets по мере необходимости,
// когда нужно будет проиграть звук, а сейчас уже проигрываются
// snd_targets звуков. По умолчанию, в этом случае, один из звуков
// выключается, тот, у которого наименьший приоритет.
#define DYNAMIC_SND_TARGETS

// Отключает возможность смены уровня сложности. Будет единственный уровень
// сложности, тот, который стоит по умолчанию, т.е. мастер.
//#define GD_MASTER_ONLY

// KRodin: Для x64 использовать новый стектрейс коллектор, т.к. старый на x64 выдаёт обрезанный стек вызовов.
// А новый выдаёт обрезанный стек на x86, как выяснилось, это норма, т.к. на стековерфлоу мне пояснили, что под 64 бита люди подумали и сделали так,
// чтобы стек можно было однозначно развернуть. Под x86 это не всегда возможно.
// И очень часто функции разворачивания стека "гадают на кофейной гуще". Blackbox походу гадает точнее, в этой ситуации.
#ifndef _M_X64
#	define XR_USE_BLACKBOX
#endif

//***********************************[Настройки отладочного режима]***********************************
// Включает макросы THROW*. В противном случае вместо них будут использоваться макросы VERIFY* (лучше пусть будет отключено, имхо)
//#define XRAY_EXCEPTIONS

// Отключить все отладочные ассерты
// Это может пригодиться в случае, если нужно отлаживать какой-нибудь мод, но отладочную сборку с этим модом запустить нереально.
// Из-за того, что в модах зачастую всё очень криво сделано, ассерты будут срабатывать на каждый чих. Это и на ОГСЕ так, на солянке - думаю, ещё хуже.
// В этом случае нужно переключиться на DEBUG конфигурацию, и раскомментировать этот дефайн:
//#define DISABLE_DBG_ASSERTIONS
//****************************************************************************************************

#ifndef SHOC_EDITION
// Включает слоты ножа, бинокля, шлема, биорадара, ПНВ, детектора артефактов, фонаря
#	define OGSE_NEW_SLOTS

// ОГСЕ-специфичная система оружейного зума. С ванильным ТЧ несовместима без правки оружейных конфигов.
#	define OGSE_WPN_ZOOM_SYSTEM
#endif

#ifdef SHOC_EDITION
// Использовать старый режим для отрисовки экранов загрузки
#   define USE_LEGACY_LOAD_SCREENS
#endif

// Что с ним, что без него - никакой разницы в FPS.
//#define USE_DOUG_LEA_ALLOCATOR_FOR_RENDER

// Включает кастомное окно с сообщением об ошибках, выключает стандартное "Прекращена работа программы..."
#define USE_OWN_ERROR_MESSAGE_WINDOW

// Включает создание минидампов при вылетах
#define USE_OWN_MINI_DUMP

// Включает вылет, если в vertex() будет передан не валидный вертекс.
//#define CRASH_ON_INVALID_VERTEX_ID

// Патроны используются только с пояса (by Karlan)
//#define AMMO_FROM_BELT

// Включает раскраску предметов в окне торговца.
//#define COLORIZE_OTHER_TRADE

// Выставлять для оружия состояние eSubstateIdleMoving при actor->is_actor_walking() || actor->is_actor_creeping() || actor->is_actor_crouching()
// Включает анимацию anim_idle_moving
//#define MORE_WPN_IDLE_MOVING_STATES

// Цена оружия будет включать в себя стоимость установленных аддонов
//#define WPN_COST_INCLUDE_ADDONS

// Изменяет принцип работы дуплета для оружия на классе CWeaponShotgun
// Вместо дуплета по кнопке прицеливания, дуплет можно включить\выключить скриптом 
// Вкдючить\выключить - wpn:get_weapon_sg():switch_duplet()
// Проверить статус - wpn:get_weapon_sg().is_duplet_enabled
// Сделано для того, что бы сохранить возможность прицеливания
//#define DUPLET_STATE_SWITCH

// Флаг позволяющий для всех предметов реагировать на флаг FRuckDefault. 
// Если флаг установлен, хабар будет подбираться в рюкзак, а не в слот по
// умолчанию. Что бы все работало нормально, нужно добавить
//
// default_to_ruck = false
//
// как минимум в секцию [bolt]. Иначе не получится доставать и кидать болт.
// А для надежности, еще и в [device_pda] и [device_torch].
//#define RUCK_FLAG_PREFERRED

// Real Wolf: блокировка перезарядки по время спринта.
//#define LOCK_RELOAD_IN_SPRINT

// Усложненный режим перезарядки. Патроны из оружия возвращаются в инвентарь
// и оружие заряжается из другой пачки с макс. кол-вом патронов. Если часто
// перезаряжаться, то через некоторое время в инвентаре будут только не полные
// пачки и оружие будет заряжаться не полностью. В пару с этим режимом
// желательно использовать ручной перепаковщик патронов, вместо
// автоматического.
//#define HARD_AMMO_RELOAD

// Отключить использование мемпулов. Пока выключаю только на x64, для экспериментов.
#ifdef _M_X64
#	define DISABLE_MEMPOOLS
#endif

#ifdef DISABLE_MEMPOOLS
// Валидатор желательно использовать только при отладке проблем с памятью. Соотв. работает только при отключенных мемпулах
//#	define USE_MEMORY_VALIDATOR
#endif

// Флаги рендера R2 по умолчанию. Включен "r_glows_use on".
#define DEF_R2_PP_FLAGS R_FLAG_GLOW_USE

// Включает учет параметра k_ap у патрона при расчета урона для НПС
// Формула такая же как при расчете урона для ГГ
// Может потребовать перенстройку конфигов патронов
//#define APPLY_ARMOR_PIERCING_TO_NPC

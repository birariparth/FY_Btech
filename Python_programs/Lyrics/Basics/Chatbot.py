MENU = {
    "1": ("Margherita",  199),
    "2": ("Pepperoni",   249),
    "3": ("BBQ Chicken", 279),
    "4": ("Veggie",      219),
    "5": ("Paneer Tikka",259),
}

SIZES = {
    "1": ("Small",  0),
    "2": ("Medium", 50),
    "3": ("Large",  100),
}

DRINKS = {
    "1": ("Coke",     49),
    "2": ("Sprite",   49),
    "3": ("Water",    20),
    "4": ("No drink",  0),
}

DELIVERY_CHARGE = 30

cart = []

print("Welcome to QuickSlice Pizza. Please enter your name")
name = input("\nYou: ").strip()
print(f"\nBot: Hey {name}, what would you like to order?")

while True:
    print("\nBot: Here is our menu:")
    for key, (name_item, price) in MENU.items():
        print(f"  [{key}] {name_item} - Rs.{price}")

    pizza_key = input("\nYou: ").strip()
    if pizza_key not in MENU:
        print("Bot: Please enter a valid option.")
        continue

    pizza_name, pizza_price = MENU[pizza_key]

    print("\nBot: What size would you like?")
    print("  [1] Small")
    print("  [2] Medium (+Rs.50)")
    print("  [3] Large (+Rs.100)")

    size_key = input("\nYou: ").strip()
    if size_key not in SIZES:
        print("Bot: Please enter a valid option.")
        continue

    size_name, size_extra = SIZES[size_key]

    print("\nBot: Would you like a drink?")
    for key, (drink, price) in DRINKS.items():
        print(f"  [{key}] {drink} - Rs.{price}")

    drink_key = input("\nYou: ").strip()
    if drink_key not in DRINKS:
        print("Bot: Please enter a valid option.")
        continue

    drink_name, drink_price = DRINKS[drink_key]
    item_total = pizza_price + size_extra + drink_price

    cart.append((size_name, pizza_name, drink_name, item_total))
    print(f"\nBot: Added {size_name} {pizza_name} with {drink_name}.")

    print("\nBot: Would you like to add another pizza?")
    print("  [1] Yes")
    print("  [2] No")

    again = input("\nYou: ").strip()
    if again == "2":
        break
    elif again != "1":
        print("Bot: Invalid input, moving ahead.")
        break

print("\nBot: Please enter your delivery address.")
address = input("\nYou: ").strip()

print("\nBot: How would you like to pay?")
print("  [1] Cash on Delivery")
print("  [2] UPI")
print("  [3] Card")

pay_options = {"1": "Cash on Delivery", "2": "UPI", "3": "Card"}
pay_key = input("\nYou: ").strip()
if pay_key in pay_options:
    payment = pay_options[pay_key]
else:
    payment = "Cash on Delivery"
    print("Bot: Invalid option, defaulting to Cash on Delivery.")

print("\nBot: Here is your order summary:")
total = 0
for size, pizza, drink, price in cart:
    print(f"  {size} {pizza} + {drink} - Rs.{price}")
    total += price
total += DELIVERY_CHARGE
print(f"  Delivery charge - Rs.{DELIVERY_CHARGE}")
print(f"  Total - Rs.{total}")
print(f"  Address - {address}")
print(f"  Payment - {payment}")

print("\nBot: Confirm your order?")
print("  [1] Yes")
print("  [2] No")

confirm = input("\nYou: ").strip()
if confirm == "1":
    print(f"\nBot: Order confirmed! Your pizza will arrive in 30 to 40 minutes. Total to pay is Rs.{total}. Thank you for ordering from QuickSlice.")
else:
    print("\nBot: Order cancelled. Come back anytime.")